//
// Created by Erwan BALLET on 20/02/2018.
//

#include <winsock2.h>
#include <ws2tcpip.h>
#include "WindowsSocket.h"
#include "../../../../ConfParser/Configuration.h"

zia::WindowsSocket::WindowsSocket(SOCKET socket) : _socket(socket) {}

zia::WindowsSocket::~WindowsSocket() {
    if (_socket != INVALID_SOCKET) {
        closesocket(_socket);
    }
}

bool zia::WindowsSocket::bind(unsigned short port) {
    int iResult;
    struct addrinfo *result = NULL;
    struct addrinfo hints;

    if (_socket != INVALID_SOCKET) {
        closesocket(_socket);
    }
    iResult = WSAStartup(MAKEWORD(2, 0), &_wsaData);
	std::cout << "StartUp : " <<  iResult << std::endl;
    if (iResult != 0)
        return false;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    iResult = getaddrinfo(NULL, std::to_string(port).c_str(), &hints, &result);
    if ( iResult != 0 ) {
        WSACleanup();
        return false;
    }
    _socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (_socket == INVALID_SOCKET) {
        freeaddrinfo(result);
        WSACleanup();
        return false;
    }
    iResult = ::bind(_socket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        freeaddrinfo(result);
        closesocket(_socket);
        WSACleanup();
        return false;
    }

    freeaddrinfo(result);

    iResult = listen(_socket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        closesocket(_socket);
        WSACleanup();
        return false;
    }
    WSACleanup();
    return true;
}

void zia::WindowsSocket::close() {
    if (_socket != INVALID_SOCKET) {
        closesocket(_socket);
        _socket = INVALID_SOCKET;
    }
}

bool zia::WindowsSocket::isOpen() const {
    return _socket != INVALID_SOCKET;
}

SOCKET &zia::WindowsSocket::getSocket() {
    return _socket;
}

bool    zia::WindowsSocket::haveAvailableInput() const {
    std::string::const_iterator   it = _buffer.begin();

    while (it != _buffer.end()) {
        if (*it == '\r' && (it + 1) != _buffer.end() && *(it + 1) == '\n') {
            return true;
        }
        ++it;
    }
    return false;
}

bool    zia::WindowsSocket::haveAvailableInput(size_t size) const {
    return _buffer.size() >= size;
}

bool    zia::WindowsSocket::setResultToBuffer(std::string &buffer, std::string &dest) {
    std::string::iterator   it = buffer.begin();

    while (it != buffer.end()) {
        if (*it == '\r' && (it + 1) != buffer.end() && *(it + 1) == '\n') {
            it = buffer.erase(it);
            it = buffer.erase(it);
            return true;
        }
        dest = dest + *it;
        it = buffer.erase(it);
    }
    return false;
}

void zia::WindowsSocket::write(const std::vector<std::byte> &message) {
    _writeList.push(message);
}

bool zia::WindowsSocket::haveSomethingToWrite() const {
    return _writeList.size() > 0;
}

void zia::WindowsSocket::flushWrite() {
    if (_writeList.size()) {
        std::string tmp;
        auto it = _writeList.front().begin();

        while (it != _writeList.front().end()) {
            tmp += *reinterpret_cast<char *>(&(*it));
            ++it;
        }
        send(_socket, tmp.c_str(), sizeof(char) * tmp.size(), 0 );
        _writeList.pop();
    }
}

std::string zia::WindowsSocket::read() {
    char tmp[READ_SIZE + 1];
    std::string result;
    int readed;

    while (!setResultToBuffer(_buffer, result)) {
        if ((readed = recv(_socket, tmp, READ_SIZE, 0)) <= 0) {
            close();
            return std::string();
        }
        std::cout << readed << std::endl;
        tmp[readed] = '\0';
        _buffer = tmp;
    }
    return result;
}

std::string zia::WindowsSocket::read(size_t size) {
    std::string res;

    if (_buffer.size() >= size) {
        auto it = _buffer.begin();
        unsigned int i = 0;

        while (i < size) {
            res += *it;
            it = _buffer.erase(it);
            ++i;
        }
    }
    return res;
}
