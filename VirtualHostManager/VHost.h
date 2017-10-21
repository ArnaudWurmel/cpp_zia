//
// Created by wurmel_a on 20/10/17.
//

#ifndef ZIA_VHOST_H
#define ZIA_VHOST_H

#include <thread>
#include <memory>
#include <condition_variable>
#include "../ConfParser/Configuration.h"
#include "Socket/ISocket.h"
#include "Socket/ISocketAcceptor.h"

namespace zia {
    class VHost {
    public:
        VHost(Configuration const&, std::condition_variable&);
        ~VHost();

    public:
        void    runVHost();
        bool    running();

    private:
        void    hostLoop();
        void    monitoreSocket(std::unique_ptr<ISocketAcceptor>&);

    private:
        std::vector<std::shared_ptr<zia::ISocket> >  _clientList;
        std::unique_ptr<std::thread>    _vhostLoop;
        Configuration   _hostConfiguration;
        std::condition_variable&    _cv;
        bool    _continue;
    };
}

#endif //ZIA_VHOST_H
