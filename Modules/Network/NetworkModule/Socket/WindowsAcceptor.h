//
// Created by Erwan BALLET on 20/02/2018.
//

#ifndef NETWORK_WINDOWSACCEPTOR_H
#define NETWORK_WINDOWSACCEPTOR_H

#ifdef _WIN32
#include <WinSock2.h>
#include "ISocketAcceptor.h"
#include "WindowsSocket.h"

namespace zia {
    class WindowsAcceptor : public zia::ISocketAcceptor {
    public:
        explicit WindowsAcceptor(unsigned short);
        ~WindowsAcceptor() override;

    public:
        void    startAccept() override;
        virtual api::ImplSocket *acceptClient();
        SOCKET& getServerSocket() override;
        void    run() override;
        void    stop() override;

    private:
        std::unique_ptr<WindowsSocket>    _serverSocket;
        unsigned short  _port;
		WSADATA	_wsaData;
    };

}
 #endif
#endif //NETWORK_WINDOWSACCEPTOR_H
