//
// Created by wurmel_a on 27/09/17.
//

#ifndef NETWORK_ISOCKET_H
#define NETWORK_ISOCKET_H

# include <queue>
# include <mutex>
# include <condition_variable>

#if __linux__
    typedef int SOCKET;
#endif

namespace zia {
    class   ISocket {
    public:
        virtual ~ISocket() {}

        virtual void    write(std::string const&) = 0;
        virtual std::string    read() = 0;
        virtual void    close() = 0;
        virtual bool    isOpen() const = 0;
        virtual SOCKET const&  getSocket() const = 0;
    };
}

#endif //NETWORK_ISOCKET_H
