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

    public:
        void    addInput(std::string const&);

    private:
        void    checkBodySize(std::string const&);

    private:
        std::string _content;
        bool    _waitingEnd;
        bool    _threated;
        api::NetInfo    _netInfos;
        bool    _mustReadBody;
        size_t  _bodySize;
        size_t  _readedSize;
        bool    _isReadingBody;
    };
}

#endif //ZIA_CLIENT_HH
