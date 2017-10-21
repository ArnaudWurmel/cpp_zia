//
// Created by wurmel_a on 20/10/17.
//

#include "VirtualHostManager.h"
#include "../ConfParser/ADirectoryReader.h"
#include "../ConfParser/AConfParser.h"
#include "../ConfParser/JsonConfParser.h"

zia::VirtualHostManager::VirtualHostManager(Configuration const& configuration) : _ziaConfiguration(configuration) {

}

bool    zia::VirtualHostManager::loadVHost() {
    std::vector<std::string> siteEnabledList = zia::ADirectoryReader::getFileNameOfDirectory(_ziaConfiguration.getSitePath());
    std::vector<std::string>::const_iterator it = siteEnabledList.begin();

    while (it != siteEnabledList.end()) {
        std::unique_ptr<AConfParser>    parser(new JsonConfParser(_ziaConfiguration.getSitePath() + "/" + *it));

        try {
            parser->loadConfiguration();
            if (!parser->checkConfiguration(zia::AConfParser::VHost)) {
                say("Can't validate configuration for : `" + *it + "`");
                return false;
            }
            _vhostList.insert(std::unique_ptr<VHost>(new VHost(parser->getConfiguration(), _conditionVariable)));
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
            return false;
        }
        ++it;
    }
    return _vhostList.size() > 0;
}

void    zia::VirtualHostManager::runVHost() {
    std::set<std::unique_ptr<VHost> >::iterator it = _vhostList.begin();
    std::mutex  condVarLocker;

    while (it != _vhostList.end()) {
        (*it)->runVHost();
        ++it;
    }
    while (_vhostList.size() > 0) {
        std::unique_lock<std::mutex>    lck(condVarLocker);

        _conditionVariable.wait_for(lck, std::chrono::milliseconds(500));
        it = _vhostList.begin();
        while (it != _vhostList.end()) {
            if (!(*it)->running()) {
                _vhostList.erase(it);
            }
            ++it;
        }
    }
}

zia::VirtualHostManager::~VirtualHostManager() {}