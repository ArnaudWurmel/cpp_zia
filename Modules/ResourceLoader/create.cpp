#include <iostream>
#include "ResourceLoader/ResourceLoader.hh"

extern "C" zia::api::Module *create() {
    return new zia::module::ResourceLoader();
}