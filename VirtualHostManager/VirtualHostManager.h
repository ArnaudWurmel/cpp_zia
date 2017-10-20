//
// Created by wurmel_a on 20/10/17.
//

#ifndef ZIA_VIRTUALHOSTMANAGER_H
#define ZIA_VIRTUALHOSTMANAGER_H

#include <set>
#include <condition_variable>
#include "../ConfParser/Configuration.h"
#include "VHost.h"

namespace zia {
    class VirtualHostManager : private Logger<VirtualHostManager> {
    public:
        VirtualHostManager(Configuration const&);
        ~VirtualHostManager();

    public:
        bool    loadVHost();
        void    runVHost();

    private:
        Configuration   _ziaConfiguration;
        std::set<std::unique_ptr<VHost> >   _vhostList;
        std::condition_variable _conditionVariable;
    };
}

#endif //ZIA_VIRTUALHOSTMANAGER_H
