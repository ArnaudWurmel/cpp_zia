//
// Created by Arnaud WURMEL on 11/02/2018.
//

#ifndef RESOURCELOADER_RESOURCELOADER_HH
#define RESOURCELOADER_RESOURCELOADER_HH

# include "../../../api/module.h"
# include "../../../Logger/Logger.hpp"
#include "File/AFile.hh"

namespace zia::module {
    class ResourceLoader : public zia::api::Module, private zia::Logger<ResourceLoader> {
    public:
        ResourceLoader();
        ~ResourceLoader() override;

    public:
        bool    config(const zia::api::Conf& conf) override;
        bool    exec(zia::api::HttpDuplex& http) override;

    private:
        bool    loadFileContent(std::shared_ptr<AFile> const& file, zia::api::HttpDuplex&);
        void    handleContentType(std::shared_ptr<AFile> const& file, zia::api::HttpDuplex&);
        void    showErrorPage(zia::api::HttpDuplex&);

    private:
        std::string _rootDirectory;
        bool    _rewriteUri;
        bool    _useErrorPage;
        std::vector<std::string>    _indexFiles;
        static std::map<std::string, std::string>  _extContentTypeMap;
        std::string _errorsPath;
    };
}


#endif //RESOURCELOADER_RESOURCELOADER_HH
