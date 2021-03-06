//
// Created by Arnaud WURMEL on 24/10/2017.
//

#ifndef ZIA_ACLIENT_HH
#define ZIA_ACLIENT_HH

#include <memory>
#include "../NetworkModule/Socket/ImplSocket.h"

namespace   zia {
    class   AClient {
    public:
        virtual ~AClient() {}

        virtual void    endOfRequest() = 0;
        virtual std::vector<std::byte>  getRequest() const = 0;
        virtual api::ImplSocket const   *getSocket() const = 0;
        virtual api::ImplSocket   *getSocket() = 0;
        virtual api::NetInfo&   getNetInfo() = 0;
        virtual bool    isReady() const = 0;
        virtual bool    mustReadBody() const = 0;
        virtual bool    isReadingBody() const = 0;
        virtual void    startReadingBody() = 0;
        virtual size_t  getBodySize() const = 0;
        virtual bool    mustKeepAlive() const = 0;
        virtual void    reset() = 0;
    };
}

#endif //ZIA_ACLIENT_HH
