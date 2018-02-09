//
// Created by Arnaud WURMEL on 20/01/2018.
//

#ifndef SERVERGAME_ADLLMANAGER_HH
#define SERVERGAME_ADLLMANAGER_HH

# include <memory>
# include "../../../api/module.h"

namespace   zia {
    template<typename T>
    class   ADLLManager {
    public:
        virtual ~ADLLManager() = default;

    public:
        virtual bool    init() = 0;
        virtual T *create() = 0;
    };
}

#endif //SERVERGAME_ADLLMANAGER_HH
