//
// Created by wurmel_a on 21/10/17.
//

#ifndef ZIA_LINUXSOCKET_H
#define ZIA_LINUXSOCKET_H

# include <netinet/in.h>
# include <sys/types.h>
# include <sys/socket.h>
# include "ISocket.h"
# include "../../Logger/Logger.h"

# define READ_SIZE (14)

namespace zia {
    class LinuxSocket : public ISocket, private Logger<LinuxSocket> {
    public:
        LinuxSocket(int socket = -1);
        ~LinuxSocket();

    public:
        virtual bool    bind(unsigned short port);
        virtual void    write(std::string const&);
        virtual std::string    read();
        virtual void    close();
        virtual bool    isOpen() const;
        virtual SOCKET&  getSocket();
        virtual bool    haveAvailableInput() const;
        virtual bool    haveSomethingToWrite() const;
        virtual void    flushWrite();

    private:
        bool    setResultToBuffer(std::string& buffer, std::string& dest);

    private:
        int _socket;
        struct in_addr  sin_addr;
        std::queue<std::string> _writeList;
        std::string _buffer;
    };
}

#endif //ZIA_LINUXSOCKET_H
