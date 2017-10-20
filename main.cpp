#include <iostream>
#include <memory>
#include "ConfParser/AConfParser.h"
#include "ConfParser/JsonConfParser.h"
#include "VirtualHostManager/VirtualHostManager.h"

int main() {
    std::unique_ptr<zia::AConfParser>   confParser(new zia::JsonConfParser());

    try {
        confParser->loadConfiguration();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    if (!confParser->checkConfiguration(zia::AConfParser::Zia)) {
        std::cerr << "Can't validate configuration" << std::endl;
        return 1;
    }
    zia::VirtualHostManager vHostManager(confParser->getConfiguration());

    try {
        if (!vHostManager.loadVHost()) {
            std::cerr << "Can't load vHost, check configuration file" << std::endl;
            return 1;
        }
        vHostManager.runVHost();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}