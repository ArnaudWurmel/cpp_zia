//
// Created by wurmel_a on 16/10/17.
//

#ifndef ZIA_CONFIGURATION_H
#define ZIA_CONFIGURATION_H

# include <string>
# include "../Logger/Logger.hpp"
# include "../api/conf.h"
# include "../api/conf.h"

namespace zia {
    class Configuration : private Logger<Configuration> {

    public:
        Configuration(api::Conf const& conf);
        ~Configuration();

    public:
        template<typename T>
        T const&    get(std::string const& key) {
            return std::get<T>(_configuration[key].v);
        }

    private:
        api::Conf   _configuration;
    };
}

#endif //ZIA_CONFIGURATION_H
