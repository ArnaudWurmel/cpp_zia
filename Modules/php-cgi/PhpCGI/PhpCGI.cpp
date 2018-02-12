//
// Created by Arnaud WURMEL on 12/02/2018.
//

#include "PhpCGI.hh"
#include "../../../ConfParser/Configuration.h"
#include "Process/AProcess.hh"

zia::module::PhpCGI::PhpCGI() = default;

bool    zia::module::PhpCGI::config(zia::api::Conf const &conf) {
    zia::Configuration  configuration(conf);

    try {
        bool value = configuration.get<bool>("debug");
        zia::LoggerConfiguration::setDebugEnabled(value);
    }
    catch (std::exception&) {}
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
    if (http.resp.headers["Content-Type"] == "text/php") {
        http.resp.headers["Content-Type"] = "text/html";
        std::shared_ptr<AProcess>   process = AProcess::get();
        std::string input;
        auto it = http.resp.body.begin();

        while (it != http.resp.body.end()) {
            input += *reinterpret_cast<char *>(&(*it));
            ++it;
        }
        if (process->execute(input, _bin)) {
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