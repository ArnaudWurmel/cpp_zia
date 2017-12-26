//
// Created by Arnaud WURMEL on 26/12/2017.
//

#include "LoggerConfiguration.hh"

bool zia::LoggerConfiguration::_debugEnabled = false;

bool const& zia::LoggerConfiguration::isDebugEnabled() {
    return _debugEnabled;
}

void    zia::LoggerConfiguration::setDebugEnabled(bool const& debugEnabled) {
    _debugEnabled = debugEnabled;
}