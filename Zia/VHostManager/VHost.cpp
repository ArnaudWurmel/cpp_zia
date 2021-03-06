//
// Created by Arnaud WURMEL on 08/02/2018.
//

#include <cstring>
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
    say(_moduleNetwork);
    say("=========================");
    _configuration = configuration;
}

bool    zia::VHost::instanciateModule() {
    _networkModule = std::unique_ptr<Module<api::Net> >(new Module<api::Net>(_moduleNetwork));

    if (!_networkModule->load(_modulePathList) || !_networkModule->get()->config(_configuration.getInitial())) {
        say("Can't load network module");
        return false;
    }
    auto iterator = _moduleList.begin();

    while (iterator != _moduleList.end()) {
        std::shared_ptr<Module<api::Module> >   module(new Module<api::Module>(*iterator));

        if (module->load(_modulePathList) && module->get()->config(_configuration.getInitial())) {
            _instanciatedModules.push_back(module);
        }
        ++iterator;
    }
    return true;
}

bool    zia::VHost::run() {
    api::Net::Callback callback = std::bind(&zia::VHost::callbackRequest, this, std::placeholders::_1, std::placeholders::_2);

    return _networkModule->get()->run(callback);
}

void    zia::VHost::callbackRequest(api::Net::Raw raw, api::NetInfo netInfo) {
    api::HttpDuplex httpDuplex;

    httpDuplex.raw_req = raw;
    httpDuplex.info = netInfo;
    httpDuplex.resp.status = zia::api::HttpResponse::Status::continue_;
    printRequest(httpDuplex);
    auto itModule = _instanciatedModules.begin();

    while (itModule != _instanciatedModules.end()) {
        (*itModule)->get()->exec(httpDuplex);
        ++itModule;
    }
    _networkModule->get()->send(netInfo.sock, httpDuplex.raw_resp);
}

void    zia::VHost::say(std::string const &message) const {
    if (LoggerConfiguration::isDebugEnabled()) {
        std::cerr << "<" << _name << "> : ";
        Logger::say(message);
    }
}

void    zia::VHost::printRequest(api::HttpDuplex& http) {
    std::string request;
    auto iterator = http.raw_req.begin();

    while (iterator != http.raw_req.end()) {
        request += *reinterpret_cast<char *>(&(*iterator));
        ++iterator;
    }
    say("Handle new request : \n" + request + "======");
}

zia::VHost::~VHost() {}