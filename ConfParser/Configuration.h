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
        void    setModulePath(std::string const&);
        void    setSitePath(std::string const&);

    public:
        std::string const&  getHost() const;
        unsigned short  getPort() const;
        std::string const&  getModulePath() const;
        std::string const&  getSitePath() const;

    private:
        std::string _host;
        std::string _modulePath;
        std::string _sitePath;
        unsigned short  _port;
    };
}

#endif //ZIA_CONFIGURATION_H
