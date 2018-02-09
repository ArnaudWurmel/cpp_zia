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

    public:
        void    addInput(std::string const&);

    private:
        api::ImplSocket *_socket;
        std::string _content;
        bool    _waitingEnd;
    };
}

#endif //ZIA_CLIENT_HH
