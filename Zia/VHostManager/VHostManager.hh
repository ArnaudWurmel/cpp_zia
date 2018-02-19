//
// Created by Arnaud WURMEL on 08/02/2018.
//

#ifndef CPP_ZIA_VHOSTMANAGER_HH
#define CPP_ZIA_VHOSTMANAGER_HH

# include <string>
# include <list>
# include "../../Logger/Logger.hpp"
# include "VHost.hh"

namespace zia {
    class VHostManager : private Logger<VHostManager> {
    public:
        explicit VHostManager(std::string const&);
        ~VHostManager();

    public:
        bool    initVHosts();
        void    run();
        bool    isRunning() const;
        void    stop();

    private:
        std::string _sitePath;
        std::list<std::shared_ptr<VHost> >  _vhostsList;
    };
}

#endif //CPP_ZIA_VHOSTMANAGER_HH
