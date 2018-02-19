//
// Created by Arnaud WURMEL on 19/02/2018.
//

#include <iostream>
#include "Logger.hh"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KWHT  "\x1B[37m"

std::map<zia::api::HttpRequest::Method, std::string> zia::module::Logger::_methodConverter = {
        { zia::api::HttpRequest::Method::get, "GET" },
        { zia::api::HttpRequest::Method::options, "OPTIONS" },
        { zia::api::HttpRequest::Method::post, "POST" },
        { zia::api::HttpRequest::Method::put, "PUT" },
        { zia::api::HttpRequest::Method::delete_, "DELETE" },
        { zia::api::HttpRequest::Method::head, "HEAD" },
        { zia::api::HttpRequest::Method::trace, "TRACE" },
        { zia::api::HttpRequest::Method::connect, "CONNECT" }
};


zia::module::Logger::Logger() {}

bool    zia::module::Logger::exec(zia::api::HttpDuplex &http) {
    std::vector<std::string>    colors;

    colors.push_back(KWHT);
    colors.push_back(KWHT);
    colors.push_back(KGRN);
    colors.push_back(KBLU);
    colors.push_back(KRED);
    colors.push_back(KRED);
    if (_methodConverter.find(http.req.method) != _methodConverter.end()) {
        int color = static_cast<int>(http.resp.status) / 100;
        if (color < colors.size()) {
            std::cout << colors[color];
        }
        std::cout << static_cast<int>(http.resp.status) << KWHT;
        std::cout << " " << _methodConverter[http.req.method] << " " << http.req.uri << std::endl;
    }
    return true;
}

bool    zia::module::Logger::config(const zia::api::Conf&) {
    return true;
}

zia::module::Logger::~Logger() = default;