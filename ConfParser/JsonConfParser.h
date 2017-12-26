//
// Created by wurmel_a on 16/10/17.
//

#ifndef ZIA_JSONCONFPARSER_H
#define ZIA_JSONCONFPARSER_H

# include <map>
# include <utility>
# include "../lib/json.hpp"
# include "AConfParser.h"

namespace zia {
    class JsonConfParser : public zia::AConfParser, private Logger<JsonConfParser> {
    public:
        JsonConfParser(std::string const& filePath = "./zia.conf");
        ~JsonConfParser() override;

    public:
        void    loadConfiguration() override;
        Configuration const&    getConfiguration() const override;

    private:
        void    setHost(nlohmann::json const&);
        void    setPort(nlohmann::json const&);
        void    setModulePath(nlohmann::json const&);
        void    setSitePath(nlohmann::json const&);
        void    setDebug(nlohmann::json const&);

    private:
        std::string _filepath;
        Configuration   _configuration;
        std::map<std::string, void (zia::JsonConfParser::*)(nlohmann::json const&) >   _parsingPtrs;
    };
}

#endif //ZIA_JSONCONFPARSER_H