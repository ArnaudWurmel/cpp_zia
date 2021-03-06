//
// Created by wurmel_a on 21/10/17.
//

#ifndef _WIN32
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <netdb.h>
#include "LinuxSocket.h"

zia::LinuxSocket::LinuxSocket(int socket) : _socket(socket) {}

bool zia::LinuxSocket::bind(unsigned short port) {
    struct protoent *pe;
    struct sockaddr_in  serv_addr;
    int enable = 1;

    if (_socket != -1) {
        ::close(_socket);
    }
    pe = getprotobyname("TCP");
    if (!pe) {
        return false;
    }
    _socket = socket(AF_INET, SOCK_STREAM, pe->p_proto);
    if (_socket == -1) {
        return false;
    }
    if (setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        perror("Error");
    }
    std::memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    if (::bind(_socket, reinterpret_cast<struct sockaddr *>(&serv_addr), sizeof(serv_addr)) == -1) {
        perror("Error");
        return false;
    }
    if (listen(_socket, 10) == -1) {
        return false;
    }
    return true;
}

void zia::LinuxSocket::write(std::vector<std::byte> const& message) {
    _writeList.push(message);
}

bool    zia::LinuxSocket::setResultToBuffer(std::string &buffer, std::string &dest) {
    std::string::iterator   it = buffer.begin();

    while (it != buffer.end()) {
        if (*it == '\r' && (it + 1) != buffer.end() && *(it + 1) == '\n') {
            buffer.erase(it);
            buffer.erase(it);
            return true;
        }
        dest = dest + *it;
        buffer.erase(it);
    }
    return false;
}

bool    zia::LinuxSocket::haveAvailableInput() const {
    std::string::const_iterator   it = _buffer.begin();

    while (it != _buffer.end()) {
        if (*it == '\r' && (it + 1) != _buffer.end() && *(it + 1) == '\n') {
            return true;
        }
        ++it;
    }
    return false;
}

bool    zia::LinuxSocket::haveAvailableInput(size_t size) const {
    return _buffer.size() >= size;
}

std::string zia::LinuxSocket::read(size_t size) {
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

std::string zia::LinuxSocket::read() {
    char tmp[READ_SIZE + 1];
    std::string result;
    ssize_t readed;

    while (!setResultToBuffer(_buffer, result)) {
        if ((readed = ::read(_socket, tmp, READ_SIZE)) <= 0) {
            close();
            return std::string();
        }
        tmp[readed] = '\0';
        _buffer = tmp;
    }
    return result;
}

void    zia::LinuxSocket::close() {
    if (_socket != -1) {
        ::close(_socket);
        _socket = -1;
    }
}

bool    zia::LinuxSocket::isOpen() const {
    return _socket != -1;
}

SOCKET&   zia::LinuxSocket::getSocket() {
    return _socket;
}

bool    zia::LinuxSocket::haveSomethingToWrite() const {
    return _writeList.size() > 0;
}

void    zia::LinuxSocket::flushWrite() {
    if (_writeList.size()) {
        ::write(_socket, _writeList.front().data(), sizeof(std::byte) * _writeList.front().size());
        _writeList.pop();
    }
}

zia::LinuxSocket::~LinuxSocket() {
    if (_socket != -1)
        close();
}
#endif
