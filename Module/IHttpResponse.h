//
// Created by wurmel_a on 13/11/17.
//

#ifndef ZIA_IHTTPRESPONSE_H
#define ZIA_IHTTPRESPONSE_H

# include <string>

namespace zia
{
    class   IHttpResponse
    {
    public:
        virtual ~IHttpResponse() {}

        virtual bool    loadPage(std::string const&) const = 0;
        virtual std::string const&  getContentOfPage() const = 0;
        virtual void    setContentOfPage() const = 0;
    };
}

#endif //ZIA_IHTTPRESPONSE_H
