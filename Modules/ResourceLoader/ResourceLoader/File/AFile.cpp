//
// Created by Arnaud WURMEL on 11/02/2018.
//

#include "AFile.hh"
#include "LinuxFile.hh"

std::shared_ptr<zia::module::AFile> zia::module::AFile::get() {
#ifndef _WIN32
    return std::shared_ptr<AFile>(new LinuxFile());
#else

#endif
}