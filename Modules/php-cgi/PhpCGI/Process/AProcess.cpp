//
// Created by Arnaud WURMEL on 12/02/2018.
//

#include "AProcess.hh"
#include "LinuxProcess.hh"
#include "WindowsProcess.h"

std::shared_ptr<zia::module::AProcess>  zia::module::AProcess::get() {
#ifndef _WIN32
    return std::shared_ptr<zia::module::AProcess>(new LinuxProcess());
#else
    return std::shared_ptr<zia::module::AProcess>(new WindowsProcess());
#endif
}