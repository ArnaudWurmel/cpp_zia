//
// Created by wurmel_a on 18/10/17.
//

#ifndef ZIA_EXCEPTIONS_H
#define ZIA_EXCEPTIONS_H

# include <exception>
# include <string>

namespace zia {
    class Exceptions : public std::exception{
    public:
        Exceptions(std::string const&);
        ~Exceptions();

    public:
        const char *what() const noexcept;

    private:
        std::string _what;

    };

    class   ParsingExcept : public Exceptions {
    public:
        ParsingExcept(std::string const&);
        ~ParsingExcept();
    };

    class   NetworkExcept : public Exceptions {
    public:
        NetworkExcept(std::string const&);
        ~NetworkExcept();
    };
}

#endif //ZIA_EXCEPTIONS_H
