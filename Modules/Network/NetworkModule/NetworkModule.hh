//
// Created by Arnaud WURMEL on 09/02/2018.
//

#ifndef NETWORK_NETWORKMODULE_HH
#define NETWORK_NETWORKMODULE_HH

# include "../../../api/net.h"
# include "Socket/ISocketAcceptor.h"

namespace zia::module {
    class NetworkModule : public api::Net {
    public:
        NetworkModule();
        ~NetworkModule();

    public:
        bool    run(Callback cb) override;
        bool    send(api::ImplSocket* sock, Raw resp) override;
        bool    stop() override;
        bool    config(const api::Conf& conf) override;

    private:
        bool    initNetwork();
        void    threadLoop();
        void    monitoreSocket();

    private:
        std::string _host;
        unsigned short _port;
        std::unique_ptr<zia::ISocketAcceptor>   _acceptor;

    private:
        std::unique_ptr<std::thread>    _threadLoop;
        bool    _continue;
        Callback    _onRequest;
        std::vector<std::shared_ptr<Client> >   _clientList;
    };
}


#endif //NETWORK_NETWORKMODULE_HH
