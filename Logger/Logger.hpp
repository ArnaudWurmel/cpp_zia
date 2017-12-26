//
// Created by Arnaud WURMEL on 25/12/2017.
//

#ifndef CPP_ZIA_LOGGER_HH
#define CPP_ZIA_LOGGER_HH

#include <string>
#include <iostream>
#include "LoggerHelper.hpp"
#include "LoggerConfiguration.hh"

namespace zia {

    template<typename T>
    class Logger {
    public:
        Logger() {
            say("Instanced");
        }

        virtual ~Logger() {
            say("Destroyed");
        }

    protected:
        void    say(std::string const& message) {
            if (LoggerConfiguration::isDebugEnabled()) {
                std::cerr << "[" << LoggerHelper<T>::get() << "] <" << message << ">" << std::endl;
            }
        }
    };
}

#endif //CPP_ZIA_LOGGER_HH
