//
// Created by wurmel_a on 13/11/17.
//

#ifndef ZIA_ICLIENT_HPP
#define ZIA_ICLIENT_HPP

#include "IHttpRequest.hpp"

namespace zia
{
    class IClient
    {
    public:
        virtual ~IClient() {}

        virtual IHttpRequest&   getHttpRequest() = 0;
        virtual IHttpRequest const&   getHttpRequest() const = 0;
        virtual IHttpRequest&   getHttpResponse() = 0;
        virtual IHttpRequest const&   getHttpResponse() const = 0;
    };
}

#endif //ZIA_ICLIENT_HPP
