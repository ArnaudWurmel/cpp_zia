//
// Created by Arnaud WURMEL on 11/02/2018.
//
#ifndef _WIN32
#include <stdlib.h>
#include "LinuxFile.hh"

zia::module::LinuxFile::LinuxFile() = default;

bool    zia::module::LinuxFile::load(std::string const& filePath) {
    if (lstat(filePath.c_str(), &_sb) == -1) {
        return false;
    }
    _path = filePath;
    return true;
}

bool    zia::module::LinuxFile::isDir() const {
    return S_ISDIR(_sb.st_mode);
}

std::string zia::module::LinuxFile::getFullPath() const {
    char    *path = nullptr;

    if ((path = realpath(_path.c_str(), nullptr)) == NULL) {
        return std::string();
    }
    std::string res(path);

    free(path);
    return res;
}

zia::module::LinuxFile::~LinuxFile() = default;

#endif