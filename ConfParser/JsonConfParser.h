//
// Created by wurmel_a on 16/10/17.
//

#ifndef ZIA_JSONCONFPARSER_H
#define ZIA_JSONCONFPARSER_H

# include "AConfParser.h"

namespace zia {
    class JsonConfParser : public zia::AConfParser, private Logger<JsonConfParser> {
    public:
        JsonConfParser();
        ~JsonConfParser();

    public:
        void    loadConfiguration();
        bool    checkConfiguration();

    private:
        Configuration   _configuration;
    };
}

#endif //ZIA_JSONCONFPARSER_H
