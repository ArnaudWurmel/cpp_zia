//
// Created by Arnaud WURMEL on 25/12/2017.
//

#include "Zia.hh"
#include "ArgParsing/ArgParsing.hh"
#include "Exceptions/Exceptions.h"
#include "../ConfParser/AConfParser.h"
#include "../ConfParser/JsonConfParser.h"

zia::Zia::Zia() {
    std::unique_ptr<AConfParser>    confParser(new JsonConfParser);

    try {
        confParser->loadConfiguration();
        _configuration = std::unique_ptr<Configuration>(new Configuration(confParser->getConfiguration()));
    }
    catch (std::exception& e) {
        say("Configuration file corrupted :`" + std::string(e.what()) + "`");
    }
}

void    zia::Zia::preloading(int ac, char **av) {
    ArgParsing  argParsing;

    if (!argParsing.parseArgument(ac, av)) {
        throw zia::ParsingExcept("Error while loading main arguments");
    }
    zia::LoggerConfiguration::setDebugEnabled(argParsing.isEnabled("-d"));
}

void    zia::Zia::initComponent() {
    try {
        if (!zia::LoggerConfiguration::isDebugEnabled() && _configuration->get<bool>("debug")) {
            zia::LoggerConfiguration::setDebugEnabled(_configuration->get<bool>("debug"));
        }
    }
    catch (std::exception& e) {
        say(e.what());
    }
    say("Test debug");
}

zia::Zia::~Zia() = default;