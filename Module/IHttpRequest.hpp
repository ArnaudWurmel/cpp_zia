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
        enum Method
        {
            GET,
            POST,
            PUT,
            DELETE,
            UPDATE
        };
    public:
        virtual ~IHttpRequest() {}

        virtual void setMethod(Method const&) = 0;
        virtual Method const& getMethod() = 0;
        virtual std::string const&  getRequestedPage() = 0;
        virtual std::string const&  getInData() const = 0;
        virtual void    setUriParameters(std::string const&, std::string const&) = 0;
        virtual std::string const& getUriParameters(std::string const&) const = 0;
    };

}

#endif //ZIA_IHTTPREQUEST_HPP
