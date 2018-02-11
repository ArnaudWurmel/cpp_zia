//
// Created by Arnaud WURMEL on 11/02/2018.
//

#ifndef RESOURCELOADER_AFILE_HH
#define RESOURCELOADER_AFILE_HH

# include <string>
# include <memory>

namespace zia::module {
    class   AFile {
    public:
        virtual ~AFile() = default;

    public:
        virtual bool    load(std::string const&) = 0;
        virtual bool    isDir() const = 0;
        virtual std::string getFullPath() const = 0;

    public:
        static std::shared_ptr<AFile>  get();
    };
}

#endif //RESOURCELOADER_AFILE_HH
