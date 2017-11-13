//
// Created by wurmel_a on 13/11/17.
//

#ifndef ZIA_IHTTPBASE_HPP
#define ZIA_IHTTPBASE_HPP

# include <string>

namespace zia
{
    class IHttpBase
    {
    public:
        virtual ~IHttpBase() {}

        virtual std::string const&  getHeader(std::string const& key) const = 0;
        virtual void    setHeader(std::string const& key, std::string const& value) = 0;
        virtual std::string format() const = 0;
    };
}

#endif //ZIA_IHTTPBASE_HPP
