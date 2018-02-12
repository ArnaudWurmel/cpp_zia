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
        bool    execute(std::string const& input, std::string const& path);
        std::string const&  getOutput() const;

    private:
        std::string _output;
    };
}
#endif

#endif //PHP_CGI_LINUXPROCESS_HH
