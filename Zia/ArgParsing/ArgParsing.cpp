//
// Created by Arnaud WURMEL on 26/12/2017.
//

#include <algorithm>
#include <iostream>
#include "ArgParsing.hh"

zia::ArgParsing::Argument::Argument(std::string const& argument) {
    _argument = argument;
    _enabled = false;
}

zia::ArgParsing::Argument::~Argument() {}

zia::ArgParsing::ArgParsing() {
    _argumentList.push_back(std::unique_ptr<Argument>(new Argument("-d")));
}

bool    zia::ArgParsing::parseArgument(int ac, char **av) {
    int i = 1;

    while (i < ac) {
        auto argumentIt = std::find_if(_argumentList.begin(), _argumentList.end(),
        [&] (std::unique_ptr<Argument> const& argument) {
            return argument->_argument == av[i];
        });
        if (argumentIt != _argumentList.end()) {
            (*argumentIt)->_enabled = true;
        }
        ++i;
    }
    return true;
}

bool    zia::ArgParsing::isEnabled(std::string const& arg) {
    auto argumentIt = std::find_if(_argumentList.begin(), _argumentList.end(),
                                   [&] (std::unique_ptr<Argument> const& argument) {
                                       return argument->_argument == arg;
                                   });
    if (argumentIt != _argumentList.end()) {
        return (*argumentIt)->_enabled;
    }
    return false;
}

zia::ArgParsing::~ArgParsing() {}