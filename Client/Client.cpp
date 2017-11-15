//
// Created by Arnaud WURMEL on 24/10/2017.
//

#include "Client.hh"

zia::Client::Client(std::shared_ptr<ISocket>& socket) {
    _waitingEnd = true;
    _socket = socket;
}

void    zia::Client::addInput(std::string const& input) {
    if (_waitingEnd)
        _content = _content + input + "\n";
    else
        say("Trying to add content after endOfRequest");
}

void    zia::Client::endOfRequest() {
    _waitingEnd = false;
}

std::shared_ptr<zia::ISocket> const& zia::Client::getSocket() const {
    return _socket;
}

std::shared_ptr<zia::ISocket>&   zia::Client::getSocket() {
    return _socket;
}

zia::Client::~Client() {}