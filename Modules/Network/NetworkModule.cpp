//
// Created by Arnaud WURMEL on 09/02/2018.
//

#include "NetworkModule.hh"
#include "../../ConfParser/Configuration.h"

zia::module::NetworkModule::NetworkModule() {}

bool    zia::module::NetworkModule::run(Callback cb) {
    return false;
}

bool    zia::module::NetworkModule::stop() {
    return false;
}

bool    zia::module::NetworkModule::send(api::ImplSocket *sock, Raw resp) {
    return false;
}

bool    zia::module::NetworkModule::config(const api::Conf &conf) {
    zia::Configuration  configuration(conf);

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
    return true;
}

zia::module::NetworkModule::~NetworkModule() = default;