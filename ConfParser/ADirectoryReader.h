//
// Created by wurmel_a on 20/10/17.
//

#ifndef ZIA_ADIRECTORYREADER_H
#define ZIA_ADIRECTORYREADER_H

# include <vector>
# include <string>

namespace zia {
    class   ADirectoryReader {
    public:
        virtual ~ADirectoryReader() {}

    public:
        virtual std::vector<std::string>    getFileNameFor(std::string const&) = 0;

    public:
        static std::vector<std::string> getFileNameOfDirectory(std::string const&);
    };
}

#endif //ZIA_ADIRECTORYREADER_H
