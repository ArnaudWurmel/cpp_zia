//
// Created by erwan on 11/02/18.
//

#ifndef HTTPRECEIVER_HTTPHANDLER_HH
#define HTTPRECEIVER_HTTPHANDLER_HH

#include "../../api/module.h"

namespace   zia::module {
    class HttpHandler {
    public:
        static bool checkVersion(zia::api::HttpDuplex&);
        static std::vector<std::function<bool (zia::api::HttpDuplex&)>>    genFuncVect();
        static void fillHttpRep(zia::api::HttpDuplex&);
    };
}


#endif //HTTPRECEIVER_HTTPHANDLER_HH
