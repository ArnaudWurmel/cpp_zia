//
// Created by wurmel_a on 16/10/17.
//

#include "JsonConfParser.h"

zia::JsonConfParser::JsonConfParser() {}

/**
 * Load json file
 * If something gone wrong :
 *  throw a ParsingException
 */
void    zia::JsonConfParser::loadConfiguration() {

}

/**
 * Verify every mandatory value in Configuration
 * @return
 * If something mandatory missing, false else true
 */
bool    zia::JsonConfParser::checkConfiguration() {
    return false;
}

/**
 * @return the current configuration
 */
zia::Configuration const&   zia::JsonConfParser::getConfiguration() const {
    return _configuration;
}

zia::JsonConfParser::~JsonConfParser() {}