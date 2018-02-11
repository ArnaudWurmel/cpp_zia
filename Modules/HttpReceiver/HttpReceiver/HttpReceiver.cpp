//
// Created by Arnaud WURMEL on 10/02/2018.
//

#include <iostream>
#include "HttpReceiver.hh"
#include "../../../ConfParser/Configuration.h"

std::map<std::string, zia::api::HttpRequest::Version>   zia::module::HttpReceiver::_versionTranslate = {
        {"HTTP/0.9", zia::api::HttpRequest::Version::http_0_9},
        {"HTTP/1.0", zia::api::HttpRequest::Version::http_1_0},
        {"HTTP/1.1", zia::api::HttpRequest::Version::http_1_1},
        {"HTTP/2.0", zia::api::HttpRequest::Version::http_2_0}
};

std::map<std::string, zia::api::HttpRequest::Method>    zia::module::HttpReceiver::_methodTranslate = {
        {"GET", zia::api::HttpRequest::Method::get},
        {"OPTIONS", zia::api::HttpRequest::Method::options},
        {"POST", zia::api::HttpRequest::Method::post},
        {"PUT", zia::api::HttpRequest::Method::put},
        {"DELETE", zia::api::HttpRequest::Method::delete_},
        {"HEAD", zia::api::HttpRequest::Method::head},
        {"TRACE", zia::api::HttpRequest::Method::trace},
        {"CONNET", zia::api::HttpRequest::Method::connect}
};

zia::module::HttpReceiver::HttpReceiver() {}

bool    zia::module::HttpReceiver::config(const zia::api::Conf& conf) {
    zia::Configuration  configuration(conf);

    try {
        bool value = configuration.get<bool>("debug");
        zia::LoggerConfiguration::setDebugEnabled(value);
    }
    catch (std::exception&) {}
    return true;
}

bool    zia::module::HttpReceiver::exec(zia::api::HttpDuplex& http) {
    std::vector<zia::api::Net::Raw> rawSplit = parseRequestByLine(http.raw_req);

    if (rawSplit.size() == 0 || !handleParseMethodUriVersion(rawSplit[0], http)) {
        //
        //  Handle error method inconnue
        //
        return false;
    }
    auto iterator = rawSplit.begin() + 1;

    while (iterator != rawSplit.end()) {
        if (!handleParseHeader(*iterator, http)) {
            //
            //  Handle error retourner une erreur 500
            //
            std::cout << "Can't parse header" << std::endl;
            return false;
        }
        ++iterator;
    }
    say("Headers parsed");
    printHeaders(http);
    return true;
}

bool    zia::module::HttpReceiver::handleParseHeader(zia::api::Net::Raw &raw, zia::api::HttpDuplex &http) {
    std::string headerLine = getStringFromRaw(raw);
    std::vector<std::string>    headerRepresentation = splitStringWithSeparator(headerLine, ": ", true);

    if (headerRepresentation.size() != 2) {
        headerRepresentation = splitStringWithSeparator(headerLine, ":", true);
    }
    if (headerRepresentation.size() == 0) {
        return false;
    }
    std::pair<std::string, std::string> header;

    header.first = headerRepresentation[0];
    if (headerRepresentation.size() == 2) {
        header.second = headerRepresentation[1];
    }
    else {
        header.second = "";
    }
    http.req.headers.insert(header);
    return true;
}

bool    zia::module::HttpReceiver::handleParseMethodUriVersion(zia::api::Net::Raw &raw, zia::api::HttpDuplex &http) {
    std::string methodPageVersion = getStringFromRaw(raw);
    std::vector<std::string>    split = splitStringWithSeparator(methodPageVersion, " ");

    if (split.size() == 3) {
        if (_versionTranslate.find(split[2]) != _versionTranslate.end()) {
            http.req.version = _versionTranslate[split[2]];
        }
        else {
            http.req.version = zia::api::HttpRequest::Version::unknown;
        }
    }
    else if (split.size() == 2) {
        http.req.version = HTTP_VERSION;
    }
    else {
        return false;
    }
    if (_methodTranslate.find(split[0]) == _methodTranslate.end()) {
        http.req.method = api::HttpRequest::Method::unknown;
        return false;
    }
    http.req.method = _methodTranslate[split[0]];
    http.req.uri = split[1];
    say("Method, uri, version parsed");
    return true;
}

std::vector<zia::api::Net::Raw> zia::module::HttpReceiver::parseRequestByLine(zia::api::Net::Raw const &raw) const {
    std::vector<zia::api::Net::Raw> res;
    auto itByte = raw.begin();

    while (itByte != raw.end()) {
        zia::api::Net::Raw  line;

        while (itByte != raw.end() && (*itByte) != std::byte('\r') && itByte + 1 != raw.end() && *(itByte + 1) != std::byte('\n')) {
            line.push_back(*itByte);
            ++itByte;
        }
        res.push_back(line);
        if (itByte != raw.end()) {
            ++itByte;
            ++itByte;
        }
    }
    return res;
}

std::string zia::module::HttpReceiver::getStringFromRaw(zia::api::Net::Raw &raw) const {
    std::string res;
    auto byteIt = raw.begin();

    while (byteIt != raw.end()) {
        res += *reinterpret_cast<char *>(&(*byteIt));
        ++byteIt;
    }
    return res;
}

std::vector<std::string>    zia::module::HttpReceiver::splitStringWithSeparator(std::string const& input,
                                                                                std::string const& separator, bool once) {
    std::vector<std::string>    res;
    auto iterator = input.begin();

    while (iterator != input.end()) {
        std::string token;
        while (iterator != input.end() && input.find(separator, iterator - input.begin()) != iterator - input.begin()) {
            token += *iterator;
            ++iterator;
        }
        res.push_back(token);
        int i = 0;
        while (iterator != input.end() && i < separator.size()) {
            ++iterator;
            ++i;
        }
        if (once) {
            std::string token;
            while (iterator != input.end()) {
                token += *iterator;
                ++iterator;
            }
            res.push_back(token);
        }
    }
    return res;
}

void    zia::module::HttpReceiver::printHeaders(zia::api::HttpDuplex const &http) const {
    auto iterator = http.req.headers.begin();

    while (iterator != http.req.headers.end()) {
        say((*iterator).first + "=" + (*iterator).second);
        ++iterator;
    }
}

zia::module::HttpReceiver::~HttpReceiver() = default;