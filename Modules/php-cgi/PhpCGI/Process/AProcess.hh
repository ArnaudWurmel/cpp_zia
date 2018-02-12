//
// Created by Arnaud WURMEL on 12/02/2018.
//

#ifndef PHP_CGI_APROCESS_HH
#define PHP_CGI_APROCESS_HH

# include <memory>

namespace zia::module {
    class AProcess {
    public:
        virtual ~AProcess() = default;

    public:
        virtual bool    execute(std::string const& input, std::string const& path) = 0;
        virtual std::string const&  getOutput() const = 0;

    public:
        static std::shared_ptr<AProcess>    get();
    };
}


#endif //PHP_CGI_APROCESS_HH
