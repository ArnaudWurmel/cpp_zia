//
// Created by wurmel_a on 16/10/17.
//

#include <stdlib.h>
#include <fstream>
#include "JsonConfParser.h"
#include "../Zia/Exceptions/Exceptions.h"
#include "../api/conf.h"

zia::JsonConfParser::JsonConfParser(std::string const& filePath) {
    _filepath = filePath;
    _parsingPtrs.insert(std::make_pair("string", std::bind(&zia::JsonConfParser::setString, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
    _parsingPtrs.insert(std::make_pair("object", std::bind(&zia::JsonConfParser::setObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
    _parsingPtrs.insert(std::make_pair("array", std::bind(&zia::JsonConfParser::setArray, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
    _parsingPtrs.insert(std::make_pair("boolean", std::bind(&zia::JsonConfParser::setBoolean, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
    _parsingPtrs.insert(std::make_pair("number", std::bind(&zia::JsonConfParser::setNumber, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
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
        _configuration.clear();
        nlohmann::json  json;// = nlohmann::json::parse(confFile);

        confFile >> json;
        recursivityLoad(_configuration, json);
        confFile.close();
    }
}

void    zia::JsonConfParser::setValueForConfiguration(api::ConfObject& rootObject, std::string const& key, nlohmann::json const& value) {
    if (_parsingPtrs.find(value.type_name()) != _parsingPtrs.end()) {
        _parsingPtrs[value.type_name()](rootObject, key, value);
    }
}

void    zia::JsonConfParser::recursivityLoad(api::ConfObject& rootObject, nlohmann::json const& jsonLoad) {
    nlohmann::json::const_iterator it = jsonLoad.begin();

    while (it != jsonLoad.end()) {
        nlohmann::json  subJson = it.value();

        if (subJson.is_null()) {
            throw zia::ParsingExcept("Null value");
        }
        setValueForConfiguration(rootObject, it.key(), subJson);
        ++it;
    }
}

void    zia::JsonConfParser::setString(api::ConfObject& rootObject, std::string const& key, nlohmann::json const& value) {
    api::ConfValue object;

    object.v = value.get<std::string>();
    rootObject.insert(std::make_pair(key, object));

}

void    zia::JsonConfParser::setArray(api::ConfObject& rootObject, std::string const& key, nlohmann::json const& value) {
    api::ConfValue object;
    std::vector<std::string> vector = value.get<std::vector<std::string> >();
    api::ConfArray array;
    auto iterator = vector.begin();

    while (iterator != vector.end()) {
        api::ConfValue valueArray;

        valueArray.v = *iterator;
        array.push_back(valueArray);
        ++iterator;
    }
    object.v = array;
    rootObject.insert(std::make_pair(key, object));
}

void    zia::JsonConfParser::setObject(api::ConfObject& rootObject, std::string const& key, nlohmann::json const& value) {
    recursivityLoad(rootObject, value);
}

void    zia::JsonConfParser::setBoolean(api::ConfObject& rootObject, std::string const& key, nlohmann::json const& value) {
    api::ConfValue object;

    object.v = value.get<bool>();
    rootObject.insert(std::make_pair(key, object));
}

void    zia::JsonConfParser::setNumber(api::ConfObject& rootObject, std::string const& key, nlohmann::json const& value) {
    api::ConfValue  object;

    object.v = value.get<long long>();
    rootObject.insert(std::make_pair(key, object));
}

/**
 * @return the current configuration
 */
zia::api::Conf const&   zia::JsonConfParser::getConfiguration() const {
    return _configuration;
}

zia::JsonConfParser::~JsonConfParser() = default;