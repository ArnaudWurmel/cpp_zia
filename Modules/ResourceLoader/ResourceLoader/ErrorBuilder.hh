//
// Created by Arnaud WURMEL on 11/02/2018.
//

#ifndef RESOURCELOADER_ERRORBUILDER_HH
#define RESOURCELOADER_ERRORBUILDER_HH

# include <string>
# include "../../../api/http.h"

namespace zia::module {
    class ErrorBuilder {
    public:
        static std::string  getErrorPage(zia::api::HttpResponse::Status);
    };
}


#endif //RESOURCELOADER_ERRORBUILDER_HH
