//
// Created by Arnaud WURMEL on 25/12/2017.
//

#ifndef CPP_ZIA_ZIA_HH
#define CPP_ZIA_ZIA_HH

#include <memory>
#include "../Logger/Logger.hpp"
#include "../ConfParser/Configuration.h"
#include "VHostManager/VHostManager.hh"

namespace zia {
    class Zia : private Logger<Zia> {
    public:
        static void preloading(int ac, char **av);

    public:
        Zia();
        ~Zia() override;

    public:
        //
        // Init component and exploit configuration for default configuration
        //
        void    initComponent();

        //
        //  Execute VHostManger::run() method for run the VHosts
        //
        void    startVHosts();

    private:
        //
        //  Load VHosts with a VHostManager
        //
        void    loadVHosts();
        void    handleInput(std::string const&);

    private:
        void    handleExit(std::vector<std::string> const&);
        void    handleReload(std::vector<std::string> const&);
        void    handleDebug(std::vector<std::string> const&);

    private:
        std::vector<std::string>    getTokenFrom(std::string const&);


        //
        //  Configuration Ressources
        //
    private:
        std::unique_ptr<VHostManager>   _vHostManager;
        std::unique_ptr<Configuration>   _configuration;
        std::string _vhostEnabledPath;

    private:
        std::map<std::string, std::function<void (std::vector<std::string> const&)> >   _functionPtrs;
    };
}

#endif //CPP_ZIA_ZIA_HH
