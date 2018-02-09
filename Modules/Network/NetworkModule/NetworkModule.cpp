//
// Created by Arnaud WURMEL on 09/02/2018.
//

#include <sys/select.h>
#include "NetworkModule.hh"
#include "../../../ConfParser/Configuration.h"
#include "../Exceptions/Exceptions.hh"

zia::module::NetworkModule::NetworkModule() {}

bool    zia::module::NetworkModule::run(Callback cb) {
    _onRequest = cb;
    _continue = true;
    _threadLoop = std::unique_ptr<std::thread>(new std::thread(&zia::module::NetworkModule::threadLoop, this));
    return _continue;
}

bool    zia::module::NetworkModule::stop() {
    _continue = false;
    if (_threadLoop) {
        _threadLoop->join();
        _threadLoop.reset();
    }
    return true;
}

bool    zia::module::NetworkModule::send(api::ImplSocket *sock, Raw resp) {
    return false;
}

bool    zia::module::NetworkModule::config(const api::Conf &conf) {
    zia::Configuration  configuration(conf);

    try {
        _host = configuration.get<std::string>(KEY_HOST);
    }
    catch (std::exception&) {
        _host = DEFAULT_HOST;
    }
    try {
        _port = configuration.get<long long>(KEY_PORT);
    }
    catch (std::exception&) {
        _port = DEFAULT_PORT;
    }
    return initNetwork();
}

bool    zia::module::NetworkModule::initNetwork() {
    _acceptor = std::unique_ptr<ISocketAcceptor>(ISocketAcceptor::getSocketAcceptor(_port));

    try {
        _acceptor->startAccept();
    }
    catch (std::exception& e) {
        std::cout << "Exception : " << e.what() << std::endl;
        return false;
    }
    return true;
}

void    zia::module::NetworkModule::threadLoop() {
    while (_continue) {
        try {
            monitoreSocket();
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void    zia::module::NetworkModule::monitoreSocket() {
    std::vector<std::shared_ptr<Client> >::iterator    it = _clientList.begin();
    fd_set  rsok;
    fd_set  wsok;

    FD_ZERO(&rsok);
    FD_ZERO(&wsok);
    FD_SET(_acceptor->getServerSocket(), &rsok);
    while (it != _clientList.end()) {
        if (!(*it)->isReady()) {
            std::cout << "Set read" << std::endl;
            FD_SET((*it)->getSocket()->getSocket(), &rsok);
        }
        if ((*it)->getSocket()->haveSomethingToWrite()) {
            FD_SET((*it)->getSocket()->getSocket(), &wsok);
        }
        ++it;
    }
    std::cout << "Before select" << std::endl;
    if (select(zia::ISocketAcceptor::getMaxFds(_clientList, _acceptor->getServerSocket()), &rsok, &wsok, NULL, NULL) == -1) {
        throw zia::module::NetworkException("Socket return -1");
    }
    if (FD_ISSET(_acceptor->getServerSocket(), &rsok)) {
        try {
            std::cout << "New client" << std::endl;
            _clientList.push_back(std::shared_ptr<Client>(new Client(_acceptor->acceptClient())));
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    it = _clientList.begin();
    while (it != _clientList.end()) {
        if (FD_ISSET((*it)->getSocket()->getSocket(), &rsok)) {
            (*it)->addInput((*it)->getSocket()->read());
            while ((*it)->getSocket()->haveAvailableInput()) {
                (*it)->addInput((*it)->getSocket()->read());
            }
        }
        if ((*it)->getSocket()->isOpen() && FD_ISSET((*it)->getSocket()->getSocket(), &wsok)) {
            (*it)->getSocket()->flushWrite();
        }
        if ((*it)->isReady()) {
            _onRequest((*it)->getRequest(), (*it)->getNetInfo());
            it = _clientList.erase(it);
        }
        else if (!(*it)->getSocket()->isOpen())
            it = _clientList.erase(it);
        else {
            ++it;
        }
    }
}

zia::module::NetworkModule::~NetworkModule() = default;