#include <iostream>
#include "../../api/module.h"
#include "HttpSender/HttpSender.hh"

extern "C" zia::api::Module *create() {
    return new zia::module::HttpSender();
}