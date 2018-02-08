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
        api::Conf const&    getConfiguration() const override;

    private:
        void    setValueForConfiguration(api::ConfObject& rootObject, std::string const&, nlohmann::json const&);
        void    recursivityLoad(api::ConfObject& rootObject, nlohmann::json const&);

    private:
        void    setString(api::ConfObject&, std::string const&, nlohmann::json const&);
        void    setArray(api::ConfObject&, std::string const&, nlohmann::json const&);
        void    setObject(api::ConfObject&, std::string const&, nlohmann::json const&);
        void    setBoolean(api::ConfObject&, std::string const&, nlohmann::json const&);
        void    setNumber(api::ConfObject&, std::string const&, nlohmann::json const&);

    private:
        api::Conf   _configuration;
        std::string _filepath;
        std::map<std::string, std::function<void (api::ConfObject&, std::string const&, nlohmann::json const&)> >   _parsingPtrs;
    };
}

#endif //ZIA_JSONCONFPARSER_H