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
# include <openssl/bio.h>
# include <openssl/ssl.h>
# include <openssl/err.h>

# define READ_SIZE (8192)
# define PASSWORD "yolo"

namespace zia {
    class LinuxSocket : public api::ImplSocket {
    public:
        LinuxSocket(int socket = -1);
        ~LinuxSocket();

    public:
        virtual bool    bind(unsigned short port);
        virtual void    write(std::vector<std::byte> const&);
        virtual std::string    read();
        virtual std::string    read(size_t size);
        virtual void    close();
        virtual bool    isOpen() const;
        virtual SOCKET&  getSocket();
        virtual bool    haveAvailableInput() const;
        virtual bool    haveAvailableInput(size_t size) const;
        virtual bool    haveSomethingToWrite() const;
        virtual void    flushWrite();
      	virtual bool 	openSSL();

    private:
        bool    setResultToBuffer(std::string& buffer, std::string& dest);
      	void	ShutdownSSL();
      	void	InitializeSSL();
      	void 	DestroySSL();

    private:
        int _socket;
        SSL_CTX *sslctx;
        SSL *cSSL;

      struct in_addr  sin_addr;
        std::queue<std::vector<std::byte> > _writeList;
        std::string _buffer;
    };
}

#endif

#endif //ZIA_LINUXSOCKET_H
