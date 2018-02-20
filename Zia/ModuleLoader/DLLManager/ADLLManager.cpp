//
// Created by Arnaud WURMEL on 20/01/2018.
//

#include "ADLLManager.hh"
#include "LinuxDLLManager.hpp"

#ifdef _WIN32
	#include "WindowsDLLManager.hpp"
#else
    #include "LinuxDLLManager.hpp"
#endif
/*
template<typename T>
std::shared_ptr<zia::ADLLManager<T>> zia::ADLLManager<T>::get(std::string const& path) {
#ifdef _WIN32
	return std::shared_ptr<zia::ADLLManager<T>>(new WindowsDLLManager<T>(path));
#else
    return std::shared_ptr<zia::ADLLManager<T>>(new LinuxDLLManager<T>(path));
#endif
}*/