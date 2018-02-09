//
// Created by Arnaud WURMEL on 08/02/2018.
//

#include <memory>
#include <vector>
#include "VHost.hh"

zia::VHost::VHost() {}

void    zia::VHost::configure(Configuration& configuration) {
    try {
        _name = configuration.get<std::string>(KEY_NAME);
    }
    catch (std::exception&) {
        _name = DEFAULT_NAME;
    }
    try {
        _host = configuration.get<std::string>(KEY_HOST);
    }
    catch (std::exception&) {
        _host = DEFAULT_HOST;
    }
    try {
        _port = configuration.get<long long>(KEY_PORT);
    }
    catch (std::exception&) {
        _port = DEFAULT_PORT;
    }
    try {
        _moduleList = configuration.getArray<std::string>(KEY_MODULES);
    }
    catch (std::exception&) {
        say("Can't load module completly");
    }
    try {
        _modulePathList = configuration.getArray<std::string>(KEY_MODULE_PATH);
    }
    catch (std::exception&) {
        _modulePathList = DEFAULT_MODULE_PATH;
    }
    try {
        _moduleNetwork = configuration.get<std::string>(KEY_MODULE_NET);
    }
    catch (std::exception&) {
        _moduleNetwork = DEFAULT_MODULE_NET;
    }
    say("=========================");
    say(_name);
    say(_host);
    say(std::to_string(_port));
    say(_moduleNetwork);
    say("=========================");
}

bool    zia::VHost::instanciateModule() {
    _networkModule = std::unique_ptr<Module<api::Net> >(new Module<api::Net>(_moduleNetwork));

    if (!_networkModule->load(_modulePathList)) {
        say("Can't load network module");
        return false;
    }

    auto iterator = _moduleList.begin();

    while (iterator != _moduleList.end()) {

        ++iterator;
    }
    return false;
}

void    zia::VHost::say(std::string const &message) {
    if (LoggerConfiguration::isDebugEnabled()) {
        std::cerr << "<" << _name << "> : ";
        Logger::say(message);
    }
}

zia::VHost::~VHost() {}