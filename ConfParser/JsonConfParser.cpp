//
// Created by wurmel_a on 16/10/17.
//

#include <stdlib.h>
#include <fstream>
#include "JsonConfParser.h"
#include "../Zia/Exceptions/Exceptions.h"

zia::JsonConfParser::JsonConfParser(std::string const& filePath) {
    _filepath = filePath;
    _parsingPtrs.insert(std::make_pair("host", &zia::JsonConfParser::setHost));
    _parsingPtrs.insert(std::make_pair("port", &zia::JsonConfParser::setPort));
    _parsingPtrs.insert(std::make_pair("site_enabled", &zia::JsonConfParser::setSitePath));
    _parsingPtrs.insert(std::make_pair("module_enabled", &zia::JsonConfParser::setModulePath));
    _parsingPtrs.insert(std::make_pair("debug", &zia::JsonConfParser::setDebug));
}

/**
 * Load json file
 * If something gone wrong :
 *  throw a ParsingException
 */
void    zia::JsonConfParser::loadConfiguration() {
    std::ifstream   confFile;

    confFile.open(_filepath);
    if (confFile.is_open()) {
        say("Configuration file opened");
        say("Parsing json file...");
        nlohmann::json  json = nlohmann::json::parse(confFile);
        nlohmann::json::iterator it = json.begin();

        while (it != json.end()) {
            if (_parsingPtrs.find(it.key()) != _parsingPtrs.end()) {
                if (it.value().is_null())
                    throw zia::ParsingExcept("Null value");
                (this->*_parsingPtrs[it.key()])(it.value());
            }
            ++it;
        }
        confFile.close();
    }
}

/**
 * @return the current configuration
 */
zia::Configuration const&   zia::JsonConfParser::getConfiguration() const {
    return _configuration;
}

void    zia::JsonConfParser::setHost(nlohmann::json const& json) {
    if (!json.is_string())
        throw zia::ParsingExcept("Not a string for host");
    _configuration.setHost(json);
}

void    zia::JsonConfParser::setPort(nlohmann::json const& json) {
    if (!json.is_number())
        throw zia::ParsingExcept("Not a number for port");
    _configuration.setPort(json.get<unsigned short>());
}

void    zia::JsonConfParser::setModulePath(nlohmann::json const& json) {
    if (!json.is_string())
        throw zia::ParsingExcept("Not a string for module_available");
    _configuration.setModulePath(json);
}

void    zia::JsonConfParser::setSitePath(nlohmann::json const& json) {
    if (!json.is_string())
        throw zia::ParsingExcept("Not a string for site_available");
    _configuration.setSitePath(json);
}

void    zia::JsonConfParser::setDebug(nlohmann::json const& json) {
    if (!json.is_boolean())
        throw zia::ParsingExcept("Not a bool for debug");
    _configuration.setDebug(json.get<bool>());
}

zia::JsonConfParser::~JsonConfParser() {}