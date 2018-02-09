//
// Created by Arnaud WURMEL on 24/10/2017.
//

#include "Client.hh"

zia::Client::Client(api::ImplSocket * socket) {
    _waitingEnd = true;
    _socket = socket;
}

void    zia::Client::addInput(std::string const& input) {
    if (_waitingEnd)
        _content = _content + input + "\n";
}

void    zia::Client::endOfRequest() {
    _waitingEnd = false;
}

zia::api::ImplSocket const *zia::Client::getSocket() const {
    return _socket;
}

zia::api::ImplSocket   *zia::Client::getSocket() {
    return _socket;
}

zia::Client::~Client() {}