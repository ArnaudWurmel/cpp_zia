//
// Created by Erwan BALLET on 20/02/2018.
//

#ifdef _WIN32
#include <WS2tcpip.h>
#include <iostream>
#include "WindowsAcceptor.h"
#include "../../Exceptions/Exceptions.hh"

zia::WindowsAcceptor::WindowsAcceptor(unsigned short port) : _port(port){
    std::cout << "Init" << std::endl;
}

void zia::WindowsAcceptor::startAccept() {
	WSAStartup(MAKEWORD(2, 0), &_wsaData);
    std::cout << "Start acccept" << std::endl;
	_serverSocket = std::unique_ptr<WindowsSocket>(new WindowsSocket());
    if (!_serverSocket->bind(_port)) {
        throw zia::module::NetworkException("Can't bind server");
    }
}

void zia::WindowsAcceptor::run() {

}

void zia::WindowsAcceptor::stop() {

}

zia::api::ImplSocket *zia::WindowsAcceptor::acceptClient() {
    struct sockaddr_in  cliAddr;
    socklen_t lengthClient = sizeof(cliAddr);
    SOCKET sockAddr;

    if ((sockAddr = accept(_serverSocket->getSocket(), (struct sockaddr *)&cliAddr, &lengthClient)) == -1) {
        throw zia::module::NetworkException("Accept failure");
    }
    return new WindowsSocket(sockAddr);
}

SOCKET &zia::WindowsAcceptor::getServerSocket() {
    return _serverSocket->getSocket();
}

zia::WindowsAcceptor::~WindowsAcceptor() = default;
 #endif