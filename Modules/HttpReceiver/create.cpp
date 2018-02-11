#include "../../api/module.h"
#include "HttpReceiver/HttpReceiver.hh"

extern "C" zia::api::Module *create() {
    return new zia::module::HttpReceiver();
}