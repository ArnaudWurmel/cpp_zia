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

zia::module::Uri::~Uri() = default;