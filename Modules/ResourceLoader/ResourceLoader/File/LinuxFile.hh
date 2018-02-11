//
// Created by Arnaud WURMEL on 11/02/2018.
//

#ifndef RESOURCELOADER_LINUXFILE_HH
#define RESOURCELOADER_LINUXFILE_HH

# include <sys/stat.h>
# include "AFile.hh"

#ifndef _WIN32
namespace zia::module {
    class LinuxFile : public AFile {
    public:
        LinuxFile();
        ~LinuxFile() override;

    public:
        bool    load(std::string const&) override;
        bool    isDir() const override;
        std::string getFullPath() const override;

    private:
        struct stat _sb;
        std::string _path;
    };
}
#endif

#endif //RESOURCELOADER_LINUXFILE_HH
