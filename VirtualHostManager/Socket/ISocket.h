//
// Created by wurmel_a on 27/09/17.
//

#ifndef NETWORK_ISOCKET_H
#define NETWORK_ISOCKET_H

# include <queue>
# include <mutex>
# include <condition_variable>

#if !_WIN32
    typedef int SOCKET;
#endif

namespace zia {
    class   ISocket {
    public:
        virtual ~ISocket() {}

        virtual bool    bind(unsigned short port) = 0;
        virtual void    write(std::string const&) = 0;
        virtual bool    haveAvailableInput() const = 0;
        virtual bool    haveSomethingToWrite() const = 0;
        virtual void    flushWrite() = 0;
        virtual std::string    read() = 0;
        virtual void    close() = 0;
        virtual bool    isOpen() const = 0;
        virtual SOCKET&  getSocket() = 0;
    };
}

#endif //NETWORK_ISOCKET_H
