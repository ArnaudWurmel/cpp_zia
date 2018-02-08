//
// Created by wurmel_a on 16/10/17.
//

#ifndef ZIA_ACONFPARSER_H
#define ZIA_ACONFPARSER_H

# include "Configuration.h"
# include "../api/conf.h"

namespace zia {
    class AConfParser {
    public:
        enum    ConfType {
            Zia,
            VHost
        };
    public:
        virtual ~AConfParser() {}

        virtual void    loadConfiguration() = 0;
        virtual api::Conf const&    getConfiguration() const = 0;
    };
}

#endif //ZIA_ACONFPARSER_H
