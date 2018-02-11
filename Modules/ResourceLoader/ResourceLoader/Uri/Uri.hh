//
// Created by Arnaud WURMEL on 11/02/2018.
//

#ifndef RESOURCELOADER_URI_HH
#define RESOURCELOADER_URI_HH

# include <string>
#include <map>

namespace zia::module {
    class Uri {
    public:
        Uri();
        ~Uri();

    public:
        bool    parse(std::string const&);
        std::string const&  getRequestedFile() const;

    private:
        std::string _requestedFile;
        std::map<std::string, std::string>  _args;
    };
}


#endif //RESOURCELOADER_URI_HH
