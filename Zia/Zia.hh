//
// Created by Arnaud WURMEL on 25/12/2017.
//

#ifndef CPP_ZIA_ZIA_HH
#define CPP_ZIA_ZIA_HH

#include "../Logger/Logger.hpp"
#include "../ConfParser/Configuration.h"

namespace zia {
    class Zia : private Logger<Zia> {
    public:
        static void preloading(int ac, char **av);

    public:
        Zia();
        ~Zia() override;

    public:
        void    initComponent();

    private:
        Configuration   _configuration;
    };
}

#endif //CPP_ZIA_ZIA_HH
