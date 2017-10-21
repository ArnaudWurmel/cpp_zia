//
// Created by wurmel_a on 27/09/17.
//

#ifndef NETWORK_ISOCKETACCEPTOR_H
#define NETWORK_ISOCKETACCEPTOR_H

#include <boost/asio/detail/shared_ptr.hpp>
# include "ISocket.h"

namespace zia {
    class   ISocketAcceptor {
    public:
        virtual ~ISocketAcceptor() {}

    public:
        virtual void    startAccept() = 0;
        virtual std::shared_ptr<zia::ISocket> acceptClient() = 0;
        virtual SOCKET&  getServerSocket() = 0;
        virtual void    run() = 0;
        virtual void    stop() = 0;

    public:
        static ISocketAcceptor  *getSocketAcceptor(unsigned short);
        static int  getMaxFds(std::vector<std::shared_ptr<ISocket> > const&, SOCKET&);
    };
}

#endif //NETWORK_ISOCKETACCEPTOR_H
