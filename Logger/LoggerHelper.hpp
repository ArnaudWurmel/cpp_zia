//
// Created by Arnaud WURMEL on 26/12/2017.
//

#ifndef CPP_ZIA_LOGGERHELPER_HPP
#define CPP_ZIA_LOGGERHELPER_HPP

namespace zia {

    class Zia;
    class ArgParsing;
    class Configuration;
    class JsonConfParser;

    template<typename T>
    struct LoggerHelper
    {
        static const char   *get() {
            return typeid(T).name();
        }
    };

    template<>
    struct LoggerHelper<zia::Zia> {
        static const char   *get() {
            return "Zia";
        }
    };

    template<>
    struct LoggerHelper<zia::ArgParsing> {
        static const char   *get() {
            return "ArgParsing";
        }
    };

    template<>
    struct LoggerHelper<zia::Configuration> {
        static const char   *get() {
            return "Configuration";
        }
    };

    template<>
    struct LoggerHelper<zia::JsonConfParser> {
        static const char   *get() {
            return "JsonConfParser";
        }
    };
}


#endif //CPP_ZIA_LOGGERHELPER_HPP