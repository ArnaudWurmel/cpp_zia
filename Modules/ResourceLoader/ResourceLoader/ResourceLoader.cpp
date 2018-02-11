//
// Created by Arnaud WURMEL on 11/02/2018.
//

#include <fstream>
#include "ResourceLoader.hh"
#include "../../../ConfParser/Configuration.h"
#include "Uri/Uri.hh"
#include "File/AFile.hh"
#include "../../../ConfParser/ADirectoryReader.h"

std::map<std::string, std::string>  zia::module::ResourceLoader::_extContentTypeMap = {
        {"html", "text/html"},
        {"css", "text/css"},
        {"csv", "text/csv"},
        {"js", "text/javascript"},
        {"xml", "text/xml"},
        {"gif", "image/gif"},
        {"jpeg", "image/jpeg"},
        {"png", "image/png"}
};

zia::module::ResourceLoader::ResourceLoader() {}

bool    zia::module::ResourceLoader::config(const zia::api::Conf &conf) {
    zia::Configuration  configuration(conf);

    try {
        bool value = configuration.get<bool>("debug");
        zia::LoggerConfiguration::setDebugEnabled(value);
    }
    catch (std::exception&) {}
    try {
        _rootDirectory = configuration.get<std::string>(KEY_ROOT);

        zia::api::Conf  subConf = configuration.get<zia::api::Conf>(KEY_RESOURCE);
        zia::Configuration  subConfiguration(subConf);

        _rewriteUri = subConfiguration.get<bool>("rewrite_uri");
        _indexFiles = subConfiguration.getArray<std::string>("index");
        _useErrorPage = subConfiguration.get<bool>("use_error_page");
        _errorsPath = subConfiguration.get<std::string>("error_pages");
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        _rootDirectory = DEFAULT_ROOT;
        _rewriteUri = false;
        _useErrorPage = false;
        _errorsPath = "";
        say("Warning: using default root for VHost");
    }
    std::shared_ptr<AFile>  root = AFile::get();

    if (!root->load(_rootDirectory) || !root->isDir()) {
        say("No directory found at rootDirectory path");
        return false;
    }
    _rootDirectory = root->getFullPath();
    say("Initialize with root : `" + _rootDirectory + "`");
    if (!_rewriteUri) {
        say("Warning: Doesn't use uri rewriting");
    }
    return true;
}

bool    zia::module::ResourceLoader::exec(zia::api::HttpDuplex &http) {
    Uri uri;

    if (uri.parse(http.req.uri) == false) {
        http.resp.status = zia::api::HttpResponse::Status::bad_request;
        showErrorPage(http);
        return false;
    }
    say("Requested file : " + uri.getRequestedFile());
    std::string completeFilePath = _rootDirectory + uri.getRequestedFile();
    std::shared_ptr<AFile>  file = AFile::get();

    if (!file->load(completeFilePath)) {
        http.resp.status = zia::api::HttpResponse::Status::not_found;
        showErrorPage(http);
        return false;
    }
    if (file->getFullPath().compare(0, _rootDirectory.size(), _rootDirectory)) {
        file->load(_rootDirectory);
    }
    std::shared_ptr<AFile>  trueFile = AFile::get();

    trueFile->load(file->getFullPath());
    if (_rewriteUri && file->isDir()) {
        auto    indexFileIt = _indexFiles.begin();
        bool    found = false;

        while (!found && indexFileIt != _indexFiles.end()) {
            std::shared_ptr<AFile>  tmpFile = AFile::get();
            std::string tmpPath = file->getFullPath() + "/" + *indexFileIt;

            if (tmpFile->load(tmpPath) && !tmpFile->isDir()) {
                found = true;
                trueFile = tmpFile;
            }
            ++indexFileIt;
        }
        if (!found) {
            http.resp.status = zia::api::HttpResponse::Status::not_found;
            showErrorPage(http);
            return false;
        }
    }
    if (trueFile->isDir()) {
        http.resp.status = zia::api::HttpResponse::Status::forbidden;
    }
    else {
        if (!loadFileContent(trueFile, http)) {
            http.resp.status = zia::api::HttpResponse::Status::internal_server_error;
        }
        else {
            http.resp.status = zia::api::HttpResponse::Status::found;
            handleContentType(trueFile, http);
        }
    }
    showErrorPage(http);
    return true;
}

bool    zia::module::ResourceLoader::loadFileContent(std::shared_ptr<AFile> const &file, zia::api::HttpDuplex& http) {
    std::ifstream t(file->getFullPath());
    std::string str;

    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(t)),
               std::istreambuf_iterator<char>());
    auto it = str.begin();

    http.resp.body.clear();
    while (it != str.end()) {
        http.resp.body.push_back(std::byte(*it));
        ++it;
    }
    return true;
}

void    zia::module::ResourceLoader::handleContentType(std::shared_ptr<AFile> const &file, zia::api::HttpDuplex& http) {
    std::string path = file->getFullPath();

    if (!path.empty()) {
        std::string ext;
        unsigned int i = path.size() - 1;

        while (i >= 0 && path[i] != '.') {
            ext += path[i];
            --i;
        }
        ext = std::string(ext.rbegin(), ext.rend());
        if (_extContentTypeMap.find(ext) != _extContentTypeMap.end()) {
            http.resp.headers["Content-Type"] = _extContentTypeMap[ext];
        }
        else {
            http.resp.headers["Content-Type"] = "text/plain";
        }
    }
}

void    zia::module::ResourceLoader::showErrorPage(zia::api::HttpDuplex& http) {
    if (_useErrorPage) {
        std::vector<std::string> files = zia::ADirectoryReader::getFileNameOfDirectory(_errorsPath);
        auto it = files.begin();

        while (it != files.end()) {
            std::string expectedName = std::to_string(static_cast<int>(http.resp.status)) + ".html";

            if ((*it) == expectedName) {
                std::shared_ptr<AFile>  file = AFile::get();

                if (file->load(_errorsPath + "/" + *it) && !file->isDir()) {
                    loadFileContent(file, http);
                    handleContentType(file, http);
                }
                return ;
            }
            ++it;
        }
    }
}

zia::module::ResourceLoader::~ResourceLoader() = default;