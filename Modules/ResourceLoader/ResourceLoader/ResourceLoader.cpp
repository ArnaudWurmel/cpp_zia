//
// Created by Arnaud WURMEL on 11/02/2018.
//

#include "ResourceLoader.hh"
#include "../../../ConfParser/Configuration.h"

zia::module::ResourceLoader::ResourceLoader() {

}

bool    zia::module::ResourceLoader::config(const zia::api::Conf &conf) {
    zia::Configuration  configuration(conf);

    try {
        bool value = configuration.get<bool>("debug");
        zia::LoggerConfiguration::setDebugEnabled(value);
    }
    catch (std::exception&) {}
    try {
        _rootDirectory = configuration.get<std::string>(KEY_ROOT);

        zia::api::Conf  subConf = configuration.get<zia::api::Conf>(KEY_RESOURCE);
        zia::Configuration  subConfiguration(subConf);

        _rewriteUri = subConfiguration.get<bool>("rewrite_uri");
        _indexFiles = subConfiguration.getArray<std::string>("index");
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        _rootDirectory = DEFAULT_ROOT;
        _rewriteUri = false;
        say("Warning: using default root for VHost");
    }
    say("Initialize with root : `" + _rootDirectory + "`");
    if (!_rewriteUri) {
        say("Warning: Doesn't use uri rewriting");
    }
    return true;
}

bool    zia::module::ResourceLoader::exec(zia::api::HttpDuplex &http) {
    say("Requested file : " + http.req.uri);
    return true;
}

zia::module::ResourceLoader::~ResourceLoader() = default;