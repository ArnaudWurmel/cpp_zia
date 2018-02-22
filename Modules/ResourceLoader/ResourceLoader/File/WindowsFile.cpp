//
// Created by marcha_1 on 13/02/2018.
//

#ifdef _WIN32
// ConsoleApplication4.cpp : Defines the entry point for the console application.
//


#include <filesystem>	
#include <iostream>
#include <atlstr.h>
#include <stdlib.h>
#include "WindowsFile.hh"

zia::module::WindowsFile::WindowsFile() = default;

bool    zia::module::WindowsFile::load(std::string const& filePath) {

	if ((_attributes = GetFileAttributes(filePath.c_str())) == INVALID_FILE_ATTRIBUTES) {
		return false;
	}
	_path = filePath;
	return true;
}

bool    zia::module::WindowsFile::isDir() const {
	if (_attributes != INVALID_FILE_ATTRIBUTES && (_attributes & FILE_ATTRIBUTE_DIRECTORY))
		return true;
	return false;
}

std::string zia::module::WindowsFile::getFullPath() const {
	std::experimental::filesystem::path p = std::experimental::filesystem::path(_path);
	return std::experimental::filesystem::absolute(p).string();
}

zia::module::WindowsFile::~WindowsFile() = default;

#endif