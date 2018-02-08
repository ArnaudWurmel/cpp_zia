#include <iostream>
#include "Zia/Zia.hh"

int main(int ac, char **av) {
    try {
        zia::Zia::preloading(ac, av);
        zia::Zia    zia;

        zia.initComponent();
        zia.startVHosts();
    }
    catch (std::exception& e) {
        return 1;
    }
    return 0;
}