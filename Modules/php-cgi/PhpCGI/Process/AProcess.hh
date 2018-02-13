//
// Created by Arnaud WURMEL on 12/02/2018.
//

#ifndef PHP_CGI_APROCESS_HH
#define PHP_CGI_APROCESS_HH

# include <memory>
# include <vector>
#include "../../../../api/net.h"

namespace zia::module {
    class AProcess {
    public:
        virtual ~AProcess() = default;

    public:
        virtual bool    execute(std::vector<std::string> const& args, std::map<std::string, std::string> const& env, zia::api::Net::Raw const&) = 0;
        virtual std::string const&  getOutput() const = 0;

    public:
        static std::shared_ptr<AProcess>    get();
    };
}


#endif //PHP_CGI_APROCESS_HH
