//
// Created by Arnaud WURMEL on 10/02/2018.
//

#ifndef HTTPSENDER_HTTPSENDER_HH
#define HTTPSENDER_HTTPSENDER_HH

# define CR '\r'
# define HttpVersion "1.1"
# define Server "Zia/0.1"

# include "../../../api/module.h"
# include "../../../api/http.h"

namespace zia::module {
    class HttpSender : public api::Module {
    public:
        HttpSender();
        ~HttpSender() override;

    public:
        bool    config(zia::api::Conf const& conf) override;
        bool    exec(zia::api::HttpDuplex& http) override;

    private:
        void    cpyFromVectorToRaw(std::vector<std::string> const&, zia::api::HttpDuplex&);
        void    endLine(zia::api::HttpDuplex&);

    private:
        std::string _host;

    private:
        static std::map<zia::api::HttpResponse::Status, std::string>    _statusMap;
    };
}


#endif //HTTPSENDER_HTTPSENDER_HH
