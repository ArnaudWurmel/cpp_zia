//
// Created by wurmel_a on 20/10/17.
//

#include "ISocketAcceptor.h"
#include "LinuxAcceptor.h"

zia::ISocketAcceptor    *zia::ISocketAcceptor::getSocketAcceptor() {
#if _WIN32
    return NULL;
#else
    return new LinuxAcceptor;
#endif
}