//
// Created by wurmel_a on 27/09/17.
//

#ifndef NETWORK_ISOCKET_H
#define NETWORK_ISOCKET_H

# include <queue>
# include <mutex>
# include <condition_variable>
# include "../../../../api/net.h"

#if !_WIN32
    typedef int SOCKET;
#endif

namespace zia {
    struct   api::ImplSocket {
    public:
        virtual ~ImplSocket() {}

        virtual bool    bind(unsigned short port) = 0;
        virtual void    write(std::vector<std::byte> const&) = 0;
        virtual bool    haveAvailableInput() const = 0;
        virtual bool    haveAvailableInput(size_t size) const = 0;
        virtual bool    haveSomethingToWrite() const = 0;
        virtual void    flushWrite() = 0;
        virtual std::string    read() = 0;
        virtual std::string     read(size_t size) = 0;
        virtual void    close() = 0;
        virtual bool    isOpen() const = 0;
        virtual SOCKET&  getSocket() = 0;
      	virtual bool 	openSSL() = 0;
    };
}

#endif //NETWORK_ISOCKET_H
