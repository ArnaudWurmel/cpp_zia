//
// Created by Arnaud WURMEL on 11/02/2018.
//

#ifndef RESOURCELOADER_RESOURCELOADER_HH
#define RESOURCELOADER_RESOURCELOADER_HH

# include "../../../api/module.h"
# include "../../../Logger/Logger.hpp"

namespace zia::module {
    class ResourceLoader : public zia::api::Module, private zia::Logger<ResourceLoader> {
    public:
        ResourceLoader();
        ~ResourceLoader() override;

    public:
        bool    config(const zia::api::Conf& conf) override;
        bool    exec(zia::api::HttpDuplex& http) override;

    private:
        std::string _rootDirectory;
        bool    _rewriteUri;
        std::vector<std::string>    _indexFiles;
    };
}


#endif //RESOURCELOADER_RESOURCELOADER_HH
