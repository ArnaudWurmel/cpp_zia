//
// Created by Arnaud WURMEL on 26/12/2017.
//

#ifndef CPP_ZIA_ARGPARSING_HH
#define CPP_ZIA_ARGPARSING_HH

# include <string>
# include <memory>
# include <vector>
# include "../../Logger/Logger.hpp"

namespace zia {
    class ArgParsing : private Logger<ArgParsing> {
    public:
        struct Argument {
            std::string _argument;
            bool    _enabled;

            Argument(std::string const& argument);
            ~Argument();
        };

    public:
        ArgParsing();
        ~ArgParsing() override;

    public:
        bool  parseArgument(int, char **);
        bool    isEnabled(std::string const&);

    private:
        std::vector<std::unique_ptr<Argument> > _argumentList;
    };
}

#endif //CPP_ZIA_ARGPARSING_HH
