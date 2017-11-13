//
// Created by wurmel_a on 13/11/17.
//

#ifndef ZIA_AMODULE_HPP
#define ZIA_AMODULE_HPP

#include <memory>
# include "IClient.hpp"

namespace zia
{
    class AModule
    {
    public:
        enum Type
        {
            PREROUTING = 0,
            POSTROUTING,
            RENDERING,
            PRESENDING,
            POSTSENDING,
            REQUESTEND
        };

        enum Priority
        {
            FATAL = 0,
            MAX,
            NOMATTER
        };

    public:
        virtual ~AModule() {}

        virtual int executeModule(std::shared_ptr<IClient>&) = 0;
        virtual std::string const& getLastError() const = 0;
        virtual Type getType() const = 0;
        virtual Priority getPriority() const = 0;
    };
}

#endif //ZIA_AMODULE_HPP
