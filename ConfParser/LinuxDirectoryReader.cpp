//
// Created by wurmel_a on 20/10/17.
//

#include <dirent.h>
#include "LinuxDirectoryReader.h"

zia::LinuxDirectoryReader::LinuxDirectoryReader() {}

std::vector<std::string>    zia::LinuxDirectoryReader::getFileNameFor(std::string const& filepath) {
    std::vector<std::string>    fileList;
    DIR *dir;
    struct dirent   *ent;

    if ((dir = opendir(filepath.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG || ent->d_type == DT_LNK)
                fileList.push_back(std::string(ent->d_name));
        }
        closedir(dir);
    }
    return fileList;
}

zia::LinuxDirectoryReader::~LinuxDirectoryReader() {}