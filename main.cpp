#include <iostream>
#include <memory>
#include "ConfParser/AConfParser.h"
#include "ConfParser/JsonConfParser.h"

int main() {
    std::unique_ptr<zia::AConfParser>   confParser(new zia::JsonConfParser());

    try {
        confParser->loadConfiguration();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    if (!confParser->checkConfiguration()) {
        std::cerr << "Can't validate configuration" << std::endl;
        return 1;
    }
    std::cout << confParser->getConfiguration().getHost() << ":" << confParser->getConfiguration().getPort() << std::endl;
    return 0;
}