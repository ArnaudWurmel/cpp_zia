//
// Created by wurmel_a on 16/10/17.
//

#include "Configuration.h"

zia::Configuration::Configuration() {
    _port = 80;
    _host = "0.0.0.0";
    _modulePath = "./modules_enabled/";
    _sitePath = "./sites_enabled/";
    _debug = false;
}

/**
 * setHost
 * @param host: new host value
 */
void    zia::Configuration::setHost(std::string const& host) {
    _host = host;
}

/**
 * getHost
 * @return the current host
 */
std::string const&  zia::Configuration::getHost() const {
    return _host;
}

/**
 * setPort
 * @param port: new port value
 */
void    zia::Configuration::setPort(unsigned short port) {
    _port = port;
}

/**
 * getPort
 * @return the current port
 */
unsigned short  zia::Configuration::getPort() const {
    return _port;
}

/**
 * setModulePath
 * @param modulePath: new module path value
 */
void    zia::Configuration::setModulePath(std::string const& modulePath) {
    _modulePath = modulePath;
}

/**
 * getModulePath
 * @return module path
 */
std::string const&  zia::Configuration::getModulePath() const {
    return _modulePath;
}

/**
 * setSitePath
 * @param modulePath: new module path value
 */
void    zia::Configuration::setSitePath(std::string const& sitePath) {
    _sitePath = sitePath;
}

/**
 * getSitePath
 * @return module path
 */
std::string const&  zia::Configuration::getSitePath() const {
    return _sitePath;
}

void    zia::Configuration::setDebug(bool const& debug) {
    _debug = debug;
}

bool const& zia::Configuration::debugEnabled() const {
    return _debug;
}

zia::Configuration::~Configuration() {}