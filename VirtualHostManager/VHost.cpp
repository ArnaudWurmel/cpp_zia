//
// Created by wurmel_a on 20/10/17.
//

#include "VHost.h"
#include "Socket/ISocketAcceptor.h"
#include "../Exceptions/Exceptions.h"

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
    std::unique_ptr<ISocketAcceptor>    socketAcceptor(ISocketAcceptor::getSocketAcceptor(_hostConfiguration.getPort()));

    try {
        socketAcceptor->startAccept();

        while (_continue) {
            monitoreSocket(socketAcceptor);
        }
    }
    catch (std::exception& e) {
        _continue = false;
        _cv.notify_one();
        return;
    }
    _cv.notify_one();
    _continue = false;
}

void    zia::VHost::monitoreSocket(std::unique_ptr<ISocketAcceptor>& socketAcceptor) {
    std::vector<std::shared_ptr<ISocket> >::iterator    it = _clientList.begin();
    fd_set  rsok;
    fd_set  wsok;

    FD_ZERO(&rsok);
    FD_ZERO(&wsok);
    FD_SET(socketAcceptor->getServerSocket(), &rsok);
    while (it != _clientList.end()) {
        FD_SET((*it)->getSocket(), &rsok);
        if ((*it)->haveSomethingToWrite()) {
            FD_SET((*it)->getSocket(), &wsok);
        }
        ++it;
    }
    if (select(zia::ISocketAcceptor::getMaxFds(_clientList, socketAcceptor->getServerSocket()), &rsok, &wsok, NULL, NULL) == -1) {
        throw zia::NetworkExcept("Socket return -1");
    }
    if (FD_ISSET(socketAcceptor->getServerSocket(), &rsok)) {
        try {
            _clientList.push_back(socketAcceptor->acceptClient());
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    it = _clientList.begin();
    std::cout << "Here" << std::endl;
    while (it != _clientList.end()) {
        if (FD_ISSET((*it)->getSocket(), &rsok)) {
            std::cout << "Readed : " << (*it)->read() << std::endl;
        }
        if ((*it)->isOpen() && FD_ISSET((*it)->getSocket(), &wsok)) {

        }
        if (!(*it)->isOpen())
            _clientList.erase(it--);
        ++it;
    }
}

zia::VHost::~VHost() {
    if (_vhostLoop.get() != nullptr) {
        _continue = false;
        if (_vhostLoop->joinable()) {
            _vhostLoop->join();
            _vhostLoop.reset();
        }
    }
}