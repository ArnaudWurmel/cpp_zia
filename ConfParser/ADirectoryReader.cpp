//
// Created by wurmel_a on 20/10/17.
//

#include <bits/unique_ptr.h>
#include "ADirectoryReader.h"
#include "LinuxDirectoryReader.h"

std::vector<std::string>    zia::ADirectoryReader::getFileNameOfDirectory(std::string const& filePath) {
    std::unique_ptr<ADirectoryReader>    reader;

#if _WIN32
    throw std::exception();
#else
    reader = std::unique_ptr<ADirectoryReader>(new LinuxDirectoryReader());
#endif
    return reader->getFileNameFor(filePath);
}