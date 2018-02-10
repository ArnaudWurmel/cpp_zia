//
// Created by wurmel_a on 21/10/17.
//

#ifndef ZIA_LINUXSOCKET_H
#define ZIA_LINUXSOCKET_H

#ifndef _WIN32
# include <list>
# include <netinet/in.h>
# include <sys/types.h>
# include <sys/socket.h>
# include "ImplSocket.h"
# include "../../../../api/net.h"

# define READ_SIZE (14)

namespace zia {
    class LinuxSocket : public api::ImplSocket {
    public:
        LinuxSocket(int socket = -1);
        ~LinuxSocket();

    public:
        virtual bool    bind(unsigned short port);
        virtual void    write(std::vector<std::byte> const&);
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
        std::queue<std::vector<std::byte> > _writeList;
        std::string _buffer;
    };
}

#endif

#endif //ZIA_LINUXSOCKET_H
