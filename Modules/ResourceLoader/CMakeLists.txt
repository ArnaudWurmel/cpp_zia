cmake_minimum_required(VERSION 3.9)
project(ResourceLoader VERSION 1.0.1 DESCRIPTION "ResourceLoader Module")

if (APPLE)
    set(CMAKE_CXX_COMPILER g++-7)
endif()

set(CMAKE_CXX_STANDARD 17)

add_library(ResourceLoader SHARED
        create.cpp
        ../../api/http.h
        ../../api/module.h
        ../../ConfParser/Configuration.cpp
        ../../ConfParser/Configuration.h
        ../../Logger/Logger.hpp
        ../../Logger/Logger.cpp
        ../../Logger/LoggerHelper.hpp
        ../../Logger/LoggerConfiguration.cpp
        ResourceLoader/ResourceLoader.cpp ResourceLoader/ResourceLoader.hh ResourceLoader/Uri/Uri.cpp ResourceLoader/Uri/Uri.hh ResourceLoader/File/AFile.hh ResourceLoader/File/AFile.cpp ResourceLoader/File/LinuxFile.cpp ResourceLoader/File/LinuxFile.hh)