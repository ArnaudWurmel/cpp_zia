//
// Created by Arnaud WURMEL on 12/02/2018.
//

#include "PhpCGI.hh"
#include "../../../ConfParser/Configuration.h"
#include "Process/AProcess.hh"
#include "Uri/Uri.hh"

std::map<zia::api::HttpRequest::Method, std::string> zia::module::PhpCGI::_methodConverter = {
        { zia::api::HttpRequest::Method::get, "GET" },
        { zia::api::HttpRequest::Method::options, "OPTIONS" },
        { zia::api::HttpRequest::Method::post, "POST" },
        { zia::api::HttpRequest::Method::put, "PUT" },
        { zia::api::HttpRequest::Method::delete_, "DELETE" },
        { zia::api::HttpRequest::Method::head, "HEAD" },
        { zia::api::HttpRequest::Method::trace, "TRACE" },
        { zia::api::HttpRequest::Method::connect, "CONNECT" }
};

zia::module::PhpCGI::PhpCGI() = default;

bool    zia::module::PhpCGI::config(zia::api::Conf const &conf) {
    zia::Configuration  configuration(conf);

    try {
        bool value = configuration.get<bool>("debug");
        zia::LoggerConfiguration::setDebugEnabled(value);
    }
    catch (std::exception&) {}
    try {
        _rootDirectory = configuration.get<std::string>(KEY_ROOT);
    }
    catch (std::exception&) {
        _rootDirectory = DEFAULT_ROOT;
    }
    try {
        zia::api::Conf  subConf = configuration.get<zia::api::Conf>("php-cgi");
        Configuration   subConfiguration(subConf);

        _bin = subConfiguration.get<std::string>("bin");
    }
    catch (std::exception& e) {
        _bin = "/usr/bin/php-cgi";
    }
    return true;
}

bool    zia::module::PhpCGI::exec(zia::api::HttpDuplex &http) {
    if (http.resp.headers["Content-Type"] == "text/php" && http.resp.status == zia::api::HttpResponse::Status::ok) {
        http.resp.headers["Content-Type"] = "text/html";
        std::shared_ptr<AProcess>   process = AProcess::get();
        std::vector<std::string>    args;
        std::map<std::string, std::string>    env;
        Uri uri;

        uri.parse(http.req.uri);
        args.push_back(_bin);
        if (_methodConverter.find(http.req.method) != _methodConverter.end()) {
            env.insert(std::make_pair("REQUEST_METHOD", _methodConverter[http.req.method]));
        }
        env.insert(std::make_pair("QUERY_STRING", uri.getArgs()));
        env.insert(std::make_pair("SCRIPT_FILENAME", _rootDirectory + "/" + uri.getRequestedFile()));
        env.insert(std::make_pair("REDIRECT_STATUS", "CGI"));
        if (http.req.headers.find("content-type") != http.req.headers.end()) {
            env.insert(std::make_pair("CONTENT_TYPE", http.req.headers["content-type"]));
        }
        if (http.req.headers.find("content-length") != http.req.headers.end()) {
            env.insert(std::make_pair("CONTENT_LENGTH", http.req.headers["content-length"]));
        }
        if (process->execute(args, env, http.req.body)) {
            std::string output = process->getOutput();
            parseHeaderFromPHP(http, output);
            return true;
        }
    }
    return false;
}

void    zia::module::PhpCGI::parseHeaderFromPHP(zia::api::HttpDuplex& http, std::string const& output) {
    auto itOut = output.begin();
    bool    end = false;

    while (!end && itOut != output.end()) {
        std::string line;

        while (itOut != output.end() && *itOut != '\r' && itOut + 1 != output.end() && *(itOut + 1) != '\n') {
            line += *itOut;
            ++itOut;
        }
        if (!line.empty()) {
            parseHeader(http, line);
        }
        else {
            end = true;
        }
        if (itOut != output.end()) {
            itOut = itOut + 2;
        }
        line.clear();
    }
    if (end && itOut != output.end()) {
        http.resp.body.clear();

        while (itOut != output.end()) {
            http.resp.body.push_back(std::byte(*itOut));
            ++itOut;
        }
    }
}

void    zia::module::PhpCGI::parseHeader(zia::api::HttpDuplex& http, std::string const& headerLine) {
    auto it = headerLine.begin();
    std::string key;
    std::string value;

    while (it != headerLine.end() && *it != ':' && it + 1 != headerLine.end() && (*it + 1) != ' ') {
        key += *it;
        ++it;
    }
    while (it != headerLine.end()) {
        value += *it;
        ++it;
    }
    if (!key.empty() && !value.empty()) {
        http.resp.headers[key] = value;
    }
}

zia::module::PhpCGI::~PhpCGI() = default;