//
// Created by Arnaud WURMEL on 20/02/2018.
//

#include "SSLConfiguration.hh"

zia::SSLConfiguration   zia::SSLConfiguration::_inst;

zia::SSLConfiguration   const&  zia::SSLConfiguration::get() {
    return _inst;
}

void    zia::SSLConfiguration::set(SSLConfiguration const& sslConfiguration) {
    _inst = sslConfiguration;
}

void    zia::SSLConfiguration::setPort(unsigned short port) {
    _port = port;
}

void    zia::SSLConfiguration::setCertificate(std::string const& key, std::string const& cert) {
    _key = key;
    _cert = cert;
}

std::string const&  zia::SSLConfiguration::getCert() const {
    return _cert;
}

std::string const&  zia::SSLConfiguration::getKey() const {
    return _key;
}

unsigned short  zia::SSLConfiguration::getPort() const {
    return _port;
}

zia::SSLConfiguration::SSLConfiguration() {
    _port = 443;
    _cert = "./zia_root/ssl/root_ca.pem";
    _key = "./zia_root/ssl/root_ca.key";
}

zia::SSLConfiguration::~SSLConfiguration() = default;