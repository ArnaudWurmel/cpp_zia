cmake_minimum_required(VERSION 3.9)
project(php-cgi VERSION 1.0.1 DESCRIPTION "ResourceLoader Module")

if (APPLE)
    set(CMAKE_CXX_COMPILER g++-7)
endif()

set(CMAKE_CXX_STANDARD 17)

add_library(php-cgi SHARED
        create.cpp
        ../../api/http.h
        ../../api/module.h
        ../../ConfParser/Configuration.cpp
        ../../ConfParser/Configuration.h
        ../../Logger/Logger.hpp
        ../../Logger/Logger.cpp
        ../../Logger/LoggerHelper.hpp
        ../../Logger/LoggerConfiguration.cpp
        ../../ConfParser/ADirectoryReader.h
        ../../ConfParser/ADirectoryReader.cpp
        ../../ConfParser/LinuxDirectoryReader.h
        ../../ConfParser/LinuxDirectoryReader.cpp
        PhpCGI/Uri/Uri.cpp
        PhpCGI/Uri/Uri.hh
        PhpCGI/PhpCGI.cpp PhpCGI/PhpCGI.hh PhpCGI/Process/AProcess.cpp PhpCGI/Process/AProcess.hh PhpCGI/Process/LinuxProcess.cpp PhpCGI/Process/LinuxProcess.hh)