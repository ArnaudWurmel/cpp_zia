//
// Created by Arnaud WURMEL on 09/02/2018.
//

#ifndef NETWORK_NETWORKMODULE_HH
#define NETWORK_NETWORKMODULE_HH

# include "../../api/net.h"

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
        std::string _host;
        unsigned short _port;
    };
}


#endif //NETWORK_NETWORKMODULE_HH
