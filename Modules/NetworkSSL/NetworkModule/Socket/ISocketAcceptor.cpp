//
// Created by wurmel_a on 20/10/17.
//

#include "ISocketAcceptor.h"
#include "LinuxAcceptor.h"

zia::ISocketAcceptor    *zia::ISocketAcceptor::getSocketAcceptor(unsigned short port) {
#if _WIN32
    return NULL;
#else
    return new LinuxAcceptor(port);
#endif
}

int zia::ISocketAcceptor::getMaxFds(std::vector<std::shared_ptr<Client> > const& clientList, SOCKET& listener) {
#if _WIN32
    return 0;
#else
    int maxFds = 0;
    std::vector<std::shared_ptr<Client> >::const_iterator  it = clientList.begin();

    while (it != clientList.end()) {
        if ((*it)->getSocket()->getSocket() > maxFds)
            maxFds = (*it)->getSocket()->getSocket();
        ++it;
    }
    if (listener > maxFds)
        maxFds = listener;
    return maxFds + 1;
#endif
}