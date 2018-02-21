//
// Created by wurmel_a on 18/10/17.
//

#include "Exceptions.hh"

zia::module::Exceptions::Exceptions(std::string const& what) : _what(what) {}

const char  *zia::module::Exceptions::what() const noexcept {
    return _what.c_str();
}

zia::module::Exceptions::~Exceptions() {}

zia::module::NetworkException::NetworkException(std::string const& what) : Exceptions("NetworkExcept `" + what + "`") {}
zia::module::NetworkException::~NetworkException() {}
