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
        std::cout << e.what() << std::endl;
		while (1);
        return 1;
    }
    return 0;
}