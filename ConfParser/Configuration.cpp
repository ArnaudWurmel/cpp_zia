//
// Created by wurmel_a on 16/10/17.
//

#include "Configuration.h"

zia::Configuration::Configuration(api::Conf const& conf) : _configuration(conf) {}

zia::api::Conf const&   zia::Configuration::getInitial() const {
    return _configuration;
}

zia::Configuration::~Configuration() {}