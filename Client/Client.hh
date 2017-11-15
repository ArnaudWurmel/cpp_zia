//
// Created by Arnaud WURMEL on 24/10/2017.
//

#ifndef ZIA_CLIENT_HH
#define ZIA_CLIENT_HH

# include "AClient.hh"
# include "../Logger/Logger.h"
# include "../VirtualHostManager/Socket/ISocket.h"

namespace zia {
    class Client : public AClient, private Logger<Client> {
    public:
        Client(std::shared_ptr<ISocket>);
        ~Client();

    public:
        void    endOfRequest();
        virtual std::shared_ptr<ISocket> const& getSocket() const;
        virtual std::shared_ptr<ISocket>&   getSocket();

    public:
        void    addInput(std::string const&);

    private:
        std::shared_ptr<ISocket>    _socket;
        std::string _content;
        bool    _waitingEnd;
    };
}

#endif //ZIA_CLIENT_HH
