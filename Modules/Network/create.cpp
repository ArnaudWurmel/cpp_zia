#include "../../api/net.h"
#include "NetworkModule.hh"

extern "C" zia::api::Net    *create() {
    return new zia::module::NetworkModule();
}