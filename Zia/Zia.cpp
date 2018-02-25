//
// Created by Arnaud WURMEL on 25/12/2017.
//

#include <thread>
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
    _functionPtrs.insert(std::make_pair("exit", std::bind(&zia::Zia::handleExit, this, std::placeholders::_1)));
    _functionPtrs.insert(std::make_pair("reload", std::bind(&zia::Zia::handleReload, this, std::placeholders::_1)));
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
        std::cout << _vhostEnabledPath << std::endl;
    }
    catch (std::exception& e) {
        say(e.what());

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
    std::string input;

    _vHostManager->run();
    std::cout << "> ";
    while (_vHostManager->isRunning() && std::getline(std::cin, input)) {
        if (!input.empty()) {
            handleInput(input);
        }
        std::cout << "> ";
    }
}

void    zia::Zia::handleInput(std::string const& input) {
    std::vector<std::string>    tokens = getTokenFrom(input);

    if (!tokens.empty() && _functionPtrs.find(tokens[0]) != _functionPtrs.end()) {
        _functionPtrs[tokens[0]](tokens);
    }
    else {
        say("Unknown command: `" + tokens[0] + "`");
    }
}

std::vector<std::string>    zia::Zia::getTokenFrom(std::string const& input) {
    std::vector<std::string>    res;
     auto it = input.begin();

    while (it != input.end()) {
        std::string token;

        while (*it != ' ' && it != input.end()) {
            token += *it;
            ++it;
        }
        if (!token.empty()) {
            res.push_back(token);
        }
        while (it != input.end() && *it == ' ') {
            ++it;
        }
    }
    return res;
}

void    zia::Zia::handleExit(std::vector<std::string> const &) {
    _vHostManager->stop();
}

void    zia::Zia::handleReload(std::vector<std::string> const &) {
    std::unique_ptr<AConfParser>    confParser(new JsonConfParser);

    try {
        confParser->loadConfiguration();
        _configuration = std::unique_ptr<Configuration>(new Configuration(confParser->getConfiguration()));
    }
    catch (std::exception& e) {
        say("Configuration file corrupted :`" + std::string(e.what()) + "`");
        throw e;
    }
    initComponent();
    _vHostManager->run();
    std::cout << "Reloaded" << std::endl;
}

zia::Zia::~Zia() = default;