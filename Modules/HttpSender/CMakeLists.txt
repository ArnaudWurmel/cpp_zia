cmake_minimum_required(VERSION 3.9)
project(HttpSender VERSION 1.0.1 DESCRIPTION "HttpSender Module")

if (APPLE)
    set(CMAKE_CXX_COMPILER g++-7)
endif()

set(CMAKE_CXX_STANDARD 17)

add_library(HttpSender SHARED
        create.cpp
        ../../api/http.h
        ../../api/module.h
        HttpSender/HttpSender.cpp HttpSender/HttpSender.hh)