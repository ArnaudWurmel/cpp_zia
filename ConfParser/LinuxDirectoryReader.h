//
// Created by wurmel_a on 20/10/17.
//

#ifndef ZIA_LINUXDIRECTORYREADER_H
#define ZIA_LINUXDIRECTORYREADER_H
#ifndef _WIN32
#include "ADirectoryReader.h"

namespace zia {
    class LinuxDirectoryReader : public ADirectoryReader {
    public:
        LinuxDirectoryReader();
        ~LinuxDirectoryReader();

    public:
        std::vector<std::string>    getFileNameFor(std::string const&);
    };
}
#endif
#endif //ZIA_LINUXDIRECTORYREADER_H
