cmake_minimum_required(VERSION 3.9)
project(Network VERSION 1.0.1 DESCRIPTION "Network module")

if(APPLE)
    set(CMAKE_CXX_COMPILER g++-7)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_library(Network SHARED
        create.cpp
        ../../api/conf.h
        ../../api/net.h
        ../../api/module.h
        ../../ConfParser/Configuration.h
        ../../ConfParser/Configuration.cpp
        NetworkModule.cpp NetworkModule.hh

        )