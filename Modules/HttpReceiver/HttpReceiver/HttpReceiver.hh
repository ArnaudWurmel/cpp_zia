//
// Created by Arnaud WURMEL on 10/02/2018.
//

#ifndef HTTPRECEIVER_HTTPRECEIVER_HH
#define HTTPRECEIVER_HTTPRECEIVER_HH

# include "../../../api/module.h"
# include "../../../Logger/Logger.hpp"

# define HTTP_VERSION zia::api::HttpRequest::Version::http_1_1

namespace zia::module {
    class HttpReceiver : public zia::api::Module, private zia::Logger<HttpReceiver> {
    public:
        HttpReceiver();
        ~HttpReceiver() override;

    public:
        bool    config(const zia::api::Conf&) override;
        bool    exec(zia::api::HttpDuplex&) override;

    private:
        bool    handleParseMethodUriVersion(zia::api::Net::Raw& raw, zia::api::HttpDuplex& http);
        bool    handleParseHeader(zia::api::Net::Raw& raw, zia::api::HttpDuplex& http);

    private:
        std::vector<zia::api::Net::Raw> parseRequestByLine(zia::api::Net::Raw const& raw) const;
        std::string getStringFromRaw(zia::api::Net::Raw& raw) const;
        std::vector<std::string>    splitStringWithSeparator(std::string const&, std::string const&, bool once = false);

    private:
        void    printHeaders(zia::api::HttpDuplex const& http) const;

    private:
        static std::map<std::string, zia::api::HttpRequest::Version>   _versionTranslate;
        static std::map<std::string, zia::api::HttpRequest::Method>    _methodTranslate;
    };
}


#endif //HTTPRECEIVER_HTTPRECEIVER_HH
