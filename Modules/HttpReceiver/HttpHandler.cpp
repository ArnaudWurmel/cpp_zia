//
// Created by erwan on 11/02/18.
//

#include <functional>
#include "HttpHandler.hh"

void zia::module::HttpHandler::fillHttpRep(zia::api::HttpDuplex &httpDuplex) {
    std::vector<std::function<bool(zia::api::HttpDuplex &)>>    funcVect = genFuncVect();
    auto    it = funcVect.begin();

    while (it != funcVect.end()) {
        if (!(*it)(httpDuplex))
            return ;
        it++;
    }
    httpDuplex.resp.status = zia::api::HttpResponse::Status::continue_;
}

std::vector<std::function<bool(zia::api::HttpDuplex &)>> zia::module::HttpHandler::genFuncVect() {
    std::vector<std::function<bool(zia::api::HttpDuplex &)>>    funcVect;

    funcVect.push_back(std::bind(&zia::module::HttpHandler::checkVersion, std::placeholders::_1));
    return (funcVect);
}

bool zia::module::HttpHandler::checkVersion(zia::api::HttpDuplex &httpDuplex) {
    if (httpDuplex.req.version != zia::api::HttpMessage::Version::http_1_1) {
        httpDuplex.resp.status = zia::api::HttpResponse::Status::http_version_not_supported;
        return false;
    }
    return true;
}
