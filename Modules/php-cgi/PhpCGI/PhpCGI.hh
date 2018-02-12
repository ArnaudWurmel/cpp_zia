//
// Created by Arnaud WURMEL on 12/02/2018.
//

#ifndef PHP_CGI_PHPCGI_HH
#define PHP_CGI_PHPCGI_HH

# include "../../../api/module.h"

namespace zia::module {
    class PhpCGI : public zia::api::Module {
    public:
        PhpCGI();
        ~PhpCGI() override;

    public:
        bool    config(zia::api::Conf const& conf) override;
        bool    exec(zia::api::HttpDuplex& http) override;

    private:
        void    parseHeaderFromPHP(zia::api::HttpDuplex&, std::string const&);
        void    parseHeader(zia::api::HttpDuplex&, std::string const&);

    private:
        std::string _bin;
    };
}


#endif //PHP_CGI_PHPCGI_HH
