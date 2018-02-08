//
// Created by wurmel_a on 16/10/17.
//

#ifndef ZIA_CONFIGURATION_H
#define ZIA_CONFIGURATION_H

# include <string>
# include "../Logger/Logger.hpp"
# include "../api/conf.h"

//
//  KEY
//
# define KEY_SITE_PATH "site_enabled"
# define KEY_MODULES "modules"
# define KEY_NAME "name"
# define KEY_HOST "host"
# define KEY_PORT "port"
# define KEY_MODULE_NET "module_net"
# define KEY_MODULE_PATH "modules_path"

//
//  DEFAULTS VALUES FOR MANDATORY VALUES
//
# define DEFAULT_SITE_PATH "./zia_root/site_enabled"
# define DEFAULT_NAME "Undefined"
# define DEFAULT_HOST "0.0.0.0"
# define DEFAULT_PORT 80
# define DEFAULT_MODULE_NET "network"
# define DEFAULT_MODULE_PATH {"."}



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

        template<typename T>
        std::vector<T>  getArray(std::string const& key) {
            std::vector<T>  objectList;
            api::ConfArray  array;

            array = std::get<api::ConfArray>(_configuration[key].v);

            auto iterator = array.begin();

            while (iterator != array.end()) {
                objectList.push_back(std::get<T>((*iterator).v));
                ++iterator;
            }
            return objectList;
        }

    private:
        api::Conf   _configuration;
    };
}

#endif //ZIA_CONFIGURATION_H
