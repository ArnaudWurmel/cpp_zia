//
// Created by Arnaud WURMEL on 08/02/2018.
//

#include <iostream>
#include <memory>
#include "../../ConfParser/AConfParser.h"
#include "../../ConfParser/ADirectoryReader.h"
#include "VHostManager.hh"
#include "../../ConfParser/JsonConfParser.h"

zia::VHostManager::VHostManager(std::string const& sitePath) {
    _sitePath = sitePath;
}

bool    zia::VHostManager::initVHosts() {
    std::vector<std::string>    confFiles = ADirectoryReader::getFileNameOfDirectory(_sitePath);
    auto iterator = confFiles.begin();

    while (iterator != confFiles.end()) {
        std::string confPath = _sitePath + "/" + *iterator;
        std::unique_ptr<AConfParser>    confParser(new JsonConfParser(confPath));

        try {
            confParser->loadConfiguration();
            Configuration   configuration(confParser->getConfiguration());
            std::shared_ptr<VHost>  vHost(new VHost);

            vHost->configure(configuration);
            if (vHost->instanciateModule()) {
                _vhostsList.push_back(vHost);
            }
        }
        catch (std::exception& e) {
            say(e.what());
        }
        ++iterator;
    }
    return _vhostsList.size() > 0;
}

void    zia::VHostManager::run() {
    auto iterator = _vhostsList.begin();

    while (iterator != _vhostsList.end()) {
        if (!(*iterator)->run()) {
            iterator = _vhostsList.erase(iterator);
        }
        else {
            ++iterator;
        }
    }
    while (_vhostsList.size());
}

zia::VHostManager::~VHostManager() = default;