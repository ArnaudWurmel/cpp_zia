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
        throw e;
    }
}

//
//  Preloading function: handling ac, av parameters for config
//      For example, handle -d and set Logger<T> configuration
//
void    zia::Zia::preloading(int ac, char **av) {
    ArgParsing  argParsing;

    if (!argParsing.parseArgument(ac, av)) {
        throw zia::ParsingExcept("Error while loading main arguments");
    }
    zia::LoggerConfiguration::setDebugEnabled(argParsing.isEnabled("-d"));
}

//
//  Init Component of the Zia.
//      This method will first exploit the configuration file.
//      It set as well the default parameters for some configuration.
//      After configuration is done, it call loadVHosts() method.
//
void    zia::Zia::initComponent() {
    try {
        if (!zia::LoggerConfiguration::isDebugEnabled() && _configuration->get<bool>("debug")) {
            zia::LoggerConfiguration::setDebugEnabled(_configuration->get<bool>("debug"));
        }
        _vhostEnabledPath = _configuration->get<std::string>(KEY_SITE_PATH);
    }
    catch (std::exception& e) {
        say(e.what());

        throw e;
        _vhostEnabledPath = DEFAULT_SITE_PATH;
    }
    say("Debug is enabled");
    loadVHosts();
}

//
//  LoadVHosts (website) enabled.
//      Firstly, instanciate a VHostManager specifying the "site_enabled" path defined in `zia.conf`
//      After that, execute VHostManger::initVHosts()
//      That call can throw if there is no VHosts available.
//
void    zia::Zia::loadVHosts() {
    _vHostManager = std::make_unique<VHostManager>(_vhostEnabledPath);

    if (!_vHostManager->initVHosts()) {
        say("Can't load any VHost");
        throw ParsingExcept("Can't load any VHost");
    }
}

//
//  Run VHosts previously loaded
//      May throw.
//
void    zia::Zia::startVHosts() {
    _vHostManager->run();
}

zia::Zia::~Zia() = default;