//
// Created by wurmel_a on 20/10/17.
//

#include "VHost.h"

zia::VHost::VHost(Configuration const& configuration, std::condition_variable& cv) : _hostConfiguration(configuration), _cv(cv) {
    _continue = false;
}

void    zia::VHost::runVHost() {
    _continue = true;
    _vhostLoop = std::unique_ptr<std::thread>(new std::thread(&zia::VHost::hostLoop, this));
}

bool    zia::VHost::running() {
    return _continue;
}

void    zia::VHost::hostLoop() {
    while (_continue) {

    }
    _continue = false;
    _cv.notify_one();
}

zia::VHost::~VHost() {
    if (_continue) {
        _continue = false;
        if (_vhostLoop->joinable()) {
            _vhostLoop->join();
        }
    }
}