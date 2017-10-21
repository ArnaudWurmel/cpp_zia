//
// Created by wurmel_a on 20/10/17.
//

#include "LinuxAcceptor.h"
#include "../../Exceptions/Exceptions.h"

zia::LinuxAcceptor::LinuxAcceptor(unsigned short port) : _port(port) {
    _serverSocket = std::unique_ptr<LinuxSocket>(new LinuxSocket);
}

void    zia::LinuxAcceptor::startAccept() {
    if (!_serverSocket->bind(_port)) {
        throw NetworkExcept("Can't bind server");
    }
}

std::shared_ptr<zia::ISocket> zia::LinuxAcceptor::acceptClient() {
    struct sockaddr_in  cliAddr;
    socklen_t lengthClient = sizeof(cliAddr);
    int sockAddr;

    if ((sockAddr = accept(_serverSocket->getSocket(), (struct sockaddr *)&cliAddr, &lengthClient)) == -1) {
        throw NetworkExcept("Accept failure");
    }
    return std::shared_ptr<zia::ISocket>(new LinuxSocket(sockAddr));
}

void    zia::LinuxAcceptor::run() {

}

void    zia::LinuxAcceptor::stop() {

}

SOCKET& zia::LinuxAcceptor::getServerSocket() {
    return _serverSocket->getSocket();
}

zia::LinuxAcceptor::~LinuxAcceptor() {}