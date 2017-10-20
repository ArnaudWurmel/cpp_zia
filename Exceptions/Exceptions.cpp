//
// Created by wurmel_a on 18/10/17.
//

#include "Exceptions.h"

zia::Exceptions::Exceptions(std::string const& what) : _what(what) {}

const char  *zia::Exceptions::what() const noexcept {
    return _what.c_str();
}

zia::Exceptions::~Exceptions() {}

zia::ParsingExcept::ParsingExcept(std::string const& what) : Exceptions("ParsingExcept `" + what + "`") {}
zia::ParsingExcept::~ParsingExcept() {}