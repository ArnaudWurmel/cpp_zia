cmake_minimum_required(VERSION 3.9)
project(HttpReceiver VERSION 1.0.1 DESCRIPTION "HttpSender Module")

if (APPLE)
    set(CMAKE_CXX_COMPILER g++-7)
endif()

set(CMAKE_CXX_STANDARD 17)

add_library(HttpReceiver SHARED
        create.cpp
        ../../api/http.h
        ../../api/module.h
        HttpReceiver/HttpReceiver.cpp HttpReceiver/HttpReceiver.hh
        ../../ConfParser/Configuration.cpp
        ../../ConfParser/Configuration.h
        ../../Logger/Logger.hpp
        ../../Logger/Logger.cpp
        ../../Logger/LoggerHelper.hpp
        ../../Logger/LoggerConfiguration.cpp
        )