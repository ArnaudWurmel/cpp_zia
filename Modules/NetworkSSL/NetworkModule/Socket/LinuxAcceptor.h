//
// Created by wurmel_a on 20/10/17.
//

#ifndef ZIA_LINUXACCEPTOR_H
#define ZIA_LINUXACCEPTOR_H

#ifndef _WIN32
# include "ISocketAcceptor.h"
#include "LinuxSocket.h"

namespace zia {
    class LinuxAcceptor : public zia::ISocketAcceptor {
    public:
        explicit LinuxAcceptor(unsigned short);
        ~LinuxAcceptor();

    public:
        virtual void    startAccept();
        virtual api::ImplSocket *acceptClient();
        virtual SOCKET& getServerSocket();
        virtual void    run();
        virtual void    stop();

    private:
        std::unique_ptr<LinuxSocket>    _serverSocket;
        unsigned short  _port;
    };

}
#endif

#endif //ZIA_LINUXACCEPTOR_H
