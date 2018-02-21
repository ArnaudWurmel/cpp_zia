//
// Created by Erwan BALLET on 20/02/2018.
//

#ifndef NETWORK_WINDOWSSOCKET_H
#define NETWORK_WINDOWSSOCKET_H

#include <windows.h>
#include "ImplSocket.h"

# define READ_SIZE (8192)

namespace zia {
    class WindowsSocket : public api::ImplSocket {
    public:
        WindowsSocket(SOCKET socket = INVALID_SOCKET);
        ~WindowsSocket();

    public:
        virtual bool bind(unsigned short port);
        virtual void write(std::vector<std::byte> const &);
        virtual std::string read();
        virtual std::string read(size_t size);
        virtual void close();
        virtual bool isOpen() const;
        virtual SOCKET &getSocket();
        virtual bool haveAvailableInput() const;
        virtual bool haveAvailableInput(size_t size) const;
        virtual bool haveSomethingToWrite() const;
        virtual void flushWrite();

    private:
        bool    setResultToBuffer(std::string& buffer, std::string& dest);

    private:
        SOCKET _socket;
        std::queue<std::vector<std::byte> > _writeList;
        std::string _buffer;
		WSADATA _wsaData;
    };
}

#endif //NETWORK_WINDOWSSOCKET_H
