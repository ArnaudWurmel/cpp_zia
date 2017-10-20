//
// Created by wurmel_a on 20/10/17.
//

#include "LinuxAcceptor.h"

zia::LinuxAcceptor::LinuxAcceptor() {}

void    zia::LinuxAcceptor::startAccept() {

}

bool    zia::LinuxAcceptor::haveAWaitingClient() {
    _queueLocker.lock();
    bool state = _clientList.size() > 0;
    _queueLocker.unlock();
    return state;
}

std::shared_ptr<zia::ISocket> zia::LinuxAcceptor::acceptClient() {
    _queueLocker.lock();
    std::shared_ptr<zia::ISocket>   client = _clientList.front();
    _clientList.pop();
    return client;
}

void    zia::LinuxAcceptor::run() {

}

void    zia::LinuxAcceptor::stop() {

}

zia::LinuxAcceptor::~LinuxAcceptor() {}