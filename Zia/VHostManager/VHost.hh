//
// Created by Arnaud WURMEL on 08/02/2018.
//

#ifndef CPP_ZIA_VHOST_HH
#define CPP_ZIA_VHOST_HH

#include "../../ConfParser/Configuration.h"
# include "../../Logger/Logger.hpp"
#include "../ModuleLoader/Module.hh"

namespace zia {
    class VHost : public Logger<VHost> {
    public:
        VHost();
        ~VHost();

    public:
        void    configure(Configuration&);
        bool    instanciateModule();

    protected:
        void    say(std::string const& message) override;

    private:
        std::vector<std::unique_ptr<Module<api::Module> > > _instanciateModules;
        std::unique_ptr<Module<api::Net> >  _networkModule;

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