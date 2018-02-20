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
        bool    requestTreated() const;
        void    requestDone();
        bool    mustReadBody() const;
        void    startReadingBody();
        bool    isReadingBody() const;
        size_t  getBodySize() const;
        bool    mustKeepAlive() const;
        void    reset();

    public:
        void    addInput(std::string const&);

    private:
        void    checkKeepAlive(std::string const&);
        void    checkBodySize(std::string const&);
        std::pair<std::string, std::string>  getHeaderFrom(std::string const&) const;

    private:
        std::string _content;
        bool    _waitingEnd;
        bool    _threated;
        api::NetInfo    _netInfos;
        bool    _mustReadBody;
        size_t  _bodySize;
        size_t  _readedSize;
        bool    _isReadingBody;
        bool    _keepAlive;
    };
}

#endif //ZIA_CLIENT_HH
