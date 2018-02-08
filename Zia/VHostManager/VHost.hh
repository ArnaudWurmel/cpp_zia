//
// Created by Arnaud WURMEL on 08/02/2018.
//

#ifndef CPP_ZIA_VHOST_HH
#define CPP_ZIA_VHOST_HH

#include "../../ConfParser/Configuration.h"
# include "../../Logger/Logger.hpp"

namespace zia {
    class VHost : public Logger<VHost> {
    public:
        VHost();
        ~VHost();

    public:
        void    configure(Configuration&);

    private:
        void    loadModules(Configuration&);

    protected:
        void    say(std::string const& message) override;

    private:
        std::string _name;
        std::string _host;
        unsigned int    _port;
        std::vector<std::string> _modulePathList;
        std::vector<std::string>    _moduleList;
        std::string _moduleNetwork;
    };
}


#endif //CPP_ZIA_VHOST_HH
