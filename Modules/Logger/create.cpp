#include <iostream>
#include "../../api/module.h"
#include "Logger/Logger.hh"

extern "C" zia::api::Module *create() {
    return new zia::module::Logger();
}