//
// Created by wurmel_a on 20/10/17.
//

#ifndef ZIA_LINUXACCEPTOR_H
#define ZIA_LINUXACCEPTOR_H

# include "ISocketAcceptor.h"

namespace zia {
    class LinuxAcceptor : public zia::ISocketAcceptor {
    public:
        LinuxAcceptor();
        ~LinuxAcceptor();

    public:
        virtual void    startAccept();
        virtual bool    haveAWaitingClient();
        virtual std::shared_ptr<zia::ISocket> acceptClient();
        virtual void    run();
        virtual void    stop();

    private:
        std::queue<std::shared_ptr<zia::ISocket> > _clientList;
        std::mutex  _queueLocker;
    };

}

#endif //ZIA_LINUXACCEPTOR_H
