//
// Created by Arnaud WURMEL on 24/10/2017.
//

#ifndef ZIA_CLIENT_HH
#define ZIA_CLIENT_HH

# include "AClient.hh"
# include "../NetworkModule/Socket/ImplSocket.h"

namespace zia {
    class Client : public AClient {
    public:
        Client(api::ImplSocket *);
        ~Client();

    public:
        void    endOfRequest();
        virtual api::ImplSocket const   *getSocket() const;
        virtual api::ImplSocket   *getSocket();
        api::NetInfo    &getNetInfo();
        std::vector<std::byte>  getRequest() const override;
        bool    isReady() const override;

    public:
        void    addInput(std::string const&);

    private:
        std::string _content;
        bool    _waitingEnd;
        api::NetInfo    _netInfos;
    };
}

#endif //ZIA_CLIENT_HH
