//
// Created by Arnaud WURMEL on 12/02/2018.
//

#ifndef PHP_CGI_LINUXPROCESS_HH
#define PHP_CGI_LINUXPROCESS_HH

# include "AProcess.hh"
#ifndef _WIN32
namespace zia::module {
    class LinuxProcess : public AProcess {
    public:
        LinuxProcess();
        ~LinuxProcess() override;

    public:
        bool    execute(std::vector<std::string> const& input, std::map<std::string, std::string> const& env, zia::api::Net::Raw const&);
        std::string const&  getOutput() const;

    private:
        std::string _output;
    };
}
#endif

#endif //PHP_CGI_LINUXPROCESS_HH
