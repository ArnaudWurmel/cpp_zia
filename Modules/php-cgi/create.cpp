#include "../../api/module.h"
#include "PhpCGI/PhpCGI.hh"

extern "C" zia::api::Module    *create() {
    return new zia::module::PhpCGI();
}