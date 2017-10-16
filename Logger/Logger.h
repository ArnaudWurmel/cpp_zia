//
// Created by wurmel_a on 16/10/17.
//

#ifndef ZIA_LOGGER_H
#define ZIA_LOGGER_H

# include <typeinfo>
# include <string>
# include <iostream>

namespace zia {
    template<typename T>
    class Logger {
    public:
        Logger() {
            say("Instancied");
        }

        virtual ~Logger() {
            say("Deleted");
        }

    protected:
        void    say(std::string const& message) {
            std::cout << "[" << typeid(T).name() << "] <" << message << ">" << std::endl;
        }
    };
}

#endif //ZIA_LOGGER_H
