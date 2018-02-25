//
// Created by Arnaud WURMEL on 10/02/2018.
//

#include <string>
#include <iostream>
#include "HttpSender.hh"

std::map<zia::api::HttpResponse::Status, std::string>    zia::module::HttpSender::_statusMap = {
        {zia::api::HttpResponse::Status::continue_, "Continue"},
        {zia::api::HttpResponse::Status::switching_protocols, "Switching Protocols"},
        {zia::api::HttpResponse::Status::ok, "OK"},
        {zia::api::HttpResponse::Status::created, "Created"},
        {zia::api::HttpResponse::Status::accepted, "Accepted"},
        {zia::api::HttpResponse::Status::nonauthoritative_information, "Non-Authoritative Information"},
        {zia::api::HttpResponse::Status::no_content, "No Content"},
        {zia::api::HttpResponse::Status::reset_content, "Reset Content"},
        {zia::api::HttpResponse::Status::partial_content, "Partial Content"},
        {zia::api::HttpResponse::Status::multiple_choices, "Multiple Choices"},
        {zia::api::HttpResponse::Status::moved_permanently, "Moved Permanently"},
        {zia::api::HttpResponse::Status::found, "Found"},
        {zia::api::HttpResponse::Status::see_other, "See Other"},
        {zia::api::HttpResponse::Status::not_modified, "Not Modified"},
        {zia::api::HttpResponse::Status::use_proxy, "Use Proxy"},
        {zia::api::HttpResponse::Status::temporary_redirect, "Temporary Redirect"},
        {zia::api::HttpResponse::Status::bad_request, "Bad Request"},
        {zia::api::HttpResponse::Status::unauthorized, "Unauthorized"},
        {zia::api::HttpResponse::Status::payment_required, "Payment Required"},
        {zia::api::HttpResponse::Status::forbidden, "Forbidden"},
        {zia::api::HttpResponse::Status::not_found, "Not Found"},
        {zia::api::HttpResponse::Status::method_not_allowed, "Method Not Allowed"},
        {zia::api::HttpResponse::Status::not_acceptable, "Not acceptable"},
        {zia::api::HttpResponse::Status::proxy_authentication_required, "Proxy Authentication Required"},
        {zia::api::HttpResponse::Status::request_timeout, "Request Time-out"},
        {zia::api::HttpResponse::Status::conflict, "Conflict"},
        {zia::api::HttpResponse::Status::gone, "Gone"},
        {zia::api::HttpResponse::Status::length_required, "Length Required"},
        {zia::api::HttpResponse::Status::precondition_failed, "Precondition Failed"},
        {zia::api::HttpResponse::Status::request_entity_too_large, "Request Entity Too Large"},
        {zia::api::HttpResponse::Status::request_uri_too_large, "Request-URI Too Long"},
        {zia::api::HttpResponse::Status::unsupported_media_type, "Unsupported Media Type"},
        {zia::api::HttpResponse::Status::requested_range_not_satisfiable, "Requested range unsatisfiable"},
        {zia::api::HttpResponse::Status::expectation_failed, "Expectation failed"},
        {zia::api::HttpResponse::Status::im_a_teapot, "I'm a teapot"},
        {zia::api::HttpResponse::Status::internal_server_error, "Internal Server Error"},
        {zia::api::HttpResponse::Status::not_implemented, "Not Implemented"},
        {zia::api::HttpResponse::Status::bad_gateway, "Bad Gateway"},
        {zia::api::HttpResponse::Status::service_unavailable, "Service Unavailable"},
        {zia::api::HttpResponse::Status::gateway_timeout, "Gateway Time-out"},
        {zia::api::HttpResponse::Status::http_version_not_supported, "Http Version not supported"}
};

zia::module::HttpSender::HttpSender() {}

bool    zia::module::HttpSender::config(const zia::api::Conf& conf) {
    return true;
}

bool    zia::module::HttpSender::exec(zia::api::HttpDuplex& http) {
    std::vector<std::string>    resp;

    http.resp.headers["Server"] = Server;
    http.resp.headers["Content-Length"] = std::to_string(static_cast<int>(http.resp.body.size()) + 1);
    if (_statusMap.find(http.resp.status) == _statusMap.end()) {
        std::cerr << "Doesn't handle type <" << static_cast<int>(http.resp.status) << ">" << std::endl;
        return false;
    }
    std::string httpHeader = std::string("HTTP/") + HttpVersion + " " + std::to_string(static_cast<int>(http.resp.status)) + " " + _statusMap[http.resp.status];

    resp.push_back(httpHeader);
    auto iterator = http.resp.headers.begin();

    while (iterator != http.resp.headers.end()) {
        resp.push_back((*iterator).first + ": " + (*iterator).second);
        ++iterator;
    }
    cpyFromVectorToRaw(resp, http);
    endLine(http);
    http.raw_resp.insert(http.raw_resp.end(), http.resp.body.begin(), http.resp.body.end());
    endLine(http);
    return true;
}

void    zia::module::HttpSender::cpyFromVectorToRaw(std::vector<std::string> const& resp, zia::api::HttpDuplex& http) {
    auto iterator = resp.begin();

    while (iterator != resp.end()) {
        auto character = (*iterator).begin();

        while (character != (*iterator).end()) {
            http.raw_resp.push_back(std::byte(*character));
            ++character;
        }
        endLine(http);
        ++iterator;
    }
}

void    zia::module::HttpSender::endLine(zia::api::HttpDuplex& http) {
    http.raw_resp.push_back(std::byte(CR));
    http.raw_resp.push_back(std::byte('\n'));
}

zia::module::HttpSender::~HttpSender() = default;
