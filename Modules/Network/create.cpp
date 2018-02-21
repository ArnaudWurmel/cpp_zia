#include "../../api/net.h"
#include "NetworkModule/NetworkModule.hh"

extern "C" {
#ifdef _WIN32
    __declspec(dllimport) zia::api::Net *create();
#else
    zia::api::Net   *create();
#endif
}

extern "C" zia::api::Net    *create() {
    return new zia::module::NetworkModule();
}