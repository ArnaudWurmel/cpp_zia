//
// Created by wurmel_a on 16/10/17.
//

#ifndef ZIA_CONFIGURATION_H
#define ZIA_CONFIGURATION_H

# include <string>
# include "../Logger/Logger.h"

namespace zia {
    class Configuration : private Logger<Configuration> {

    public:
        Configuration();
        ~Configuration();

    public:
        void    setHost(std::string const&);
        void    setPort(unsigned short);

    public:
        std::string const&  getHost() const;
        unsigned short  getPort() const;

    private:
        std::string _host;
        unsigned short  _port;
    };
}

#endif //ZIA_CONFIGURATION_H
