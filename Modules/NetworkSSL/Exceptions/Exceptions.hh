//
// Created by Arnaud WURMEL on 09/02/2018.
//

#ifndef NETWORK_EXCEPTIONS_HH
#define NETWORK_EXCEPTIONS_HH

#include <string>
#include <exception>

namespace zia::module {
    class Exceptions : public std::exception{
    public:
        Exceptions(std::string const&);
        ~Exceptions();

    public:
        const char *what() const noexcept;

    private:
        std::string _what;

    };

    class   NetworkException : public Exceptions {
    public:
        NetworkException(std::string const&);
        ~NetworkException();
    };
}


#endif //NETWORK_EXCEPTIONS_HH
