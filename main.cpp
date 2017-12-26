#include <iostream>
#include "Zia/Zia.hh"

int main(int ac, char **av) {
    try {
        zia::Zia::preloading(ac, av);
        zia::Zia    zia;

        zia.initComponent();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}