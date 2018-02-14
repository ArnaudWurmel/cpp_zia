//
// Created by marcha_1 on 2/02/18.
//

#ifndef ZIA_WINDOWSDIRECTORYREADER_H
#define ZIA_WINDOWSDIRECTORYREADER_H

#include "ADirectoryReader.h"

namespace zia {
    class WindowsDirectoryReader : public ADirectoryReader {
    public:
        WindowsDirectoryReader();
        ~WindowsDirectoryReader();

    public:
        std::vector<std::string>    getFileNameFor(std::string const&);
	private:
		std::wstring s2ws(const std::string& s);
    };
}

#endif //ZIA_WINDOWSDIRECTORYREADER_H