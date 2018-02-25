//
// Created by Arnaud WURMEL on 24/10/2017.
//

#include <iostream>
#include <cctype>
#include "Client.hh"
#include "../../HttpReceiver/HttpReceiver/HttpReceiver.hh"

zia::Client::Client(api::ImplSocket * socket) {
    _waitingEnd = true;
    _netInfos.sock = socket;
    _threated = false;
    _mustReadBody = false;
    _bodySize = 0;
    _readedSize = 0;
    _isReadingBody = false;
    _keepAlive = true;
}

void    zia::Client::addInput(std::string const& input) {
    if (input.empty() && !_mustReadBody) {
        if (!_content.empty()) {
            endOfRequest();
        }
    }
    else if (_waitingEnd) {
        checkKeepAlive(input);
        if (_isReadingBody) {
            _readedSize += input.size();
            _content = _content + input;
        }
        else {
            _content = _content + input + "\r\n";
        }
        if (input.empty() && _mustReadBody) {
            startReadingBody();
        }
        if (!_mustReadBody) {
            checkBodySize(input);
        }
        if (_mustReadBody && _readedSize == _bodySize && _isReadingBody) {
            endOfRequest();
        }
    }
}

size_t zia::Client::getBodySize() const {
    return _bodySize;
}

bool    zia::Client::isReadingBody() const {
    return _isReadingBody;
}

void    zia::Client::startReadingBody() {
    _isReadingBody = true;
}

void    zia::Client::checkBodySize(std::string const& input) {
	try {
		std::pair<std::string, std::string> header = getHeaderFrom(input);
		_mustReadBody = std::equal(header.first.begin(), header.first.end(), std::string("Content-Length").begin(), [](auto a, auto b) {return std::tolower(a) == std::tolower(b);});
		if (_mustReadBody) {
			_bodySize = std::stoi(header.second);
		}
	}
	catch (std::exception&) {}
}

void    zia::Client::checkKeepAlive(std::string const& input) {
	try {
		std::pair<std::string, std::string> header = getHeaderFrom(input);

		bool state = std::equal(header.first.begin(), header.first.end(), std::string("Connection").begin(), [](auto a, auto b) {return std::tolower(a) == std::tolower(b);});
		if (state) {
			_keepAlive = std::equal(header.second.begin(), header.second.end(), std::string("keep-alive").begin(), [](auto a, auto b) {return std::tolower(a) == std::tolower(b);});
		}
	}
	catch (std::exception&) {}
}

void    zia::Client::endOfRequest() {
    _waitingEnd = false;
}

zia::api::ImplSocket const *zia::Client::getSocket() const {
    return _netInfos.sock;
}

zia::api::ImplSocket   *zia::Client::getSocket() {
    return _netInfos.sock;
}

zia::api::NetInfo&  zia::Client::getNetInfo() {
    return _netInfos;
}

std::vector<std::byte>  zia::Client::getRequest() const {
    std::vector<std::byte>  request;
    auto it = _content.begin();

    while (it != _content.end()) {
        request.push_back(std::byte(*it));
        ++it;
    }
    return request;
}

std::pair<std::string, std::string>  zia::Client::getHeaderFrom(std::string const& input) const {
    std::vector<std::string>    headerRepresentation = zia::module::HttpReceiver::splitStringWithSeparator(input, ": ", true);
    std::pair<std::string, std::string> header;

    if (headerRepresentation.size() != 2) {
        headerRepresentation = zia::module::HttpReceiver::splitStringWithSeparator(input, ":", true);
    }
    if (headerRepresentation.size() != 0) {
		throw std::exception();
    }

    header.first = headerRepresentation[0];
    if (headerRepresentation.size() == 2) {
        header.second = headerRepresentation[1];
    }
    else {
        header.second = "";
    }
    return header;
}

bool    zia::Client::requestTreated() const {
    return _threated;
}

void    zia::Client::requestDone() {
    _threated = true;
}

bool    zia::Client::isReady() const {
    return !_waitingEnd;
}

bool    zia::Client::mustReadBody() const {
    return _mustReadBody;
}

void    zia::Client::reset() {
    _content.clear();
    _threated = false;
    _mustReadBody = false;
    _bodySize = 0;
    _readedSize = 0;
    _isReadingBody = false;
    _keepAlive = false;
    _waitingEnd = true;
}

bool    zia::Client::mustKeepAlive() const {
    return _keepAlive;
}

zia::Client::~Client() {}
