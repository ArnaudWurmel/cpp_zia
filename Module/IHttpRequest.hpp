//
// Created by wurmel_a on 13/11/17.
//

#ifndef ZIA_IHTTPREQUEST_HPP
#define ZIA_IHTTPREQUEST_HPP

# include "IHttpBase.hpp"

namespace zia
{
    class   IHttpRequest : public zia::IHttpBase
    {
    public:
        virtual ~IHttpRequest() {}

        virtual std::string const& getMethod() = 0;
        virtual std::string const&  getRequestedPage() = 0;
        virtual std::string const&  getInData() const = 0;
    };

}

#endif //ZIA_IHTTPREQUEST_HPP
