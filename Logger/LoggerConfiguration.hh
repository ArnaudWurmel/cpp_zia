//
// Created by Arnaud WURMEL on 26/12/2017.
//

#ifndef CPP_ZIA_LOGGERCONFIGURATION_HH
#define CPP_ZIA_LOGGERCONFIGURATION_HH

namespace zia {
    class LoggerConfiguration {
    public:
        static bool const& isDebugEnabled();
        static void    setDebugEnabled(bool const&);

    private:
        static bool    _debugEnabled;
    };
}

#endif //CPP_ZIA_LOGGERCONFIGURATION_HH
