//
// Created by Arnaud WURMEL on 11/02/2018.
//

#include "Uri.hh"

zia::module::Uri::Uri() = default;

bool    zia::module::Uri::parse(std::string const& uri) {
    auto iterator = uri.begin();

    while (iterator != uri.end() && *iterator != '?') {
        _requestedFile += *iterator;
        ++iterator;
    }
    while (iterator != uri.end()) {
        _args += *iterator;
        ++iterator;
    }
    return !_requestedFile.empty();
}

std::string const&  zia::module::Uri::getRequestedFile() const {
    return _requestedFile;
}

std::string const&  zia::module::Uri::getArgs() const {
    return _args;
}

std::map<std::string, std::string>  zia::module::Uri::getArgsMap() const {
    std::map<std::string, std::string>  res;
    auto it = getArgs().begin();

    if (it != getArgs().end() && *it == '?') {
        ++it;
        while (it != getArgs().end()) {
            std::string key;
            std::string value;

            while (it != getArgs().end() && *it != '=' && *it != '&') {
                key += *it;
                ++it;
            }
            if (it != getArgs().end() && *it == '=') {
                ++it;
                while (it != getArgs().end() && *it != '&') {
                    value += *it;
                    ++it;
                }
            }
            res.insert(std::make_pair(key, value));
            if (it != getArgs().end() && *it == '&') {
                ++it;
            }
        }
    }
    return res;
}

zia::module::Uri::~Uri() = default;