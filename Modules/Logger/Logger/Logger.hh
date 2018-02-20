//
// Created by Arnaud WURMEL on 19/02/2018.
//

#ifndef LOGGER_LOGGER_HH
#define LOGGER_LOGGER_HH

# include <map>
# include "../../../api/module.h"

namespace zia::module {
    class Logger : public zia::api::Module {
    public:
        Logger();
        ~Logger();

    public:
        bool    config(const zia::api::Conf& conf) override;
        bool    exec(zia::api::HttpDuplex& http) override;

    private:
        static std::map<zia::api::HttpRequest::Method, std::string> _methodConverter;
    };
}


#endif //LOGGER_LOGGER_HH
