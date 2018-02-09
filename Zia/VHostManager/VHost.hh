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
        bool    run();

    protected:
        void    say(std::string const& message) override;

    private:
        void    callbackRequest(api::Net::Raw, api::NetInfo);

    private:
        std::vector<std::shared_ptr<Module<api::Module> > > _instanciatedModules;
        std::unique_ptr<Module<api::Net> >  _networkModule;

    private:
        std::string _name;
        std::vector<std::string> _modulePathList;
        std::vector<std::string>    _moduleList;
        std::string _moduleNetwork;
        Configuration   _configuration;
    };
}


#endif //CPP_ZIA_VHOST_HH
