//
// Created by Arnaud WURMEL on 24/10/2017.
//

#include <iostream>
#include "Client.hh"

zia::Client::Client(api::ImplSocket * socket) {
    _waitingEnd = true;
    _netInfos.sock = socket;
    _threated = false;
}

void    zia::Client::addInput(std::string const& input) {
    if (input.empty()) {
        endOfRequest();
    }
    else if (_waitingEnd)
        _content = _content + input + "\n";
}

void    zia::Client::endOfRequest() {
    _waitingEnd = false;
}

zia::api::ImplSocket const *zia::Client::getSocket() const {
    return _netInfos.sock;
}

zia::api::ImplSocket   *zia::Client::getSocket() {
    return _netInfos.sock;
}

zia::api::NetInfo&  zia::Client::getNetInfo() {
    return _netInfos;
}

std::vector<std::byte>  zia::Client::getRequest() const {
    std::vector<std::byte>  request;
    auto it = _content.begin();

    while (it != _content.end()) {
        request.push_back(std::byte(*it));
        ++it;
    }
    return request;
}

bool    zia::Client::requestTreated() const {
    return _threated;
}

void    zia::Client::requestDone() {
    _threated = true;
}

bool    zia::Client::isReady() const {
    return !_waitingEnd;
}

zia::Client::~Client() {}