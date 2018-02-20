cmake_minimum_required(VERSION 3.9)
project(Network VERSION 1.0.1 DESCRIPTION "Network module")

if(APPLE)
    set(CMAKE_CXX_COMPILER g++-7)
endif()

if (NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif()

add_library(Network SHARED
        create.cpp
        ../../api/conf.h
        ../../api/net.h
        ../../api/module.h
        ../../ConfParser/Configuration.h
        ../../ConfParser/Configuration.cpp
        NetworkModule/NetworkModule.cpp NetworkModule/NetworkModule.hh
        NetworkModule/Socket/ImplSocket.h
        NetworkModule/Socket/ISocketAcceptor.h
        NetworkModule/Socket/ISocketAcceptor.cpp
        NetworkModule/Socket/LinuxAcceptor.cpp
        NetworkModule/Socket/LinuxAcceptor.h
        NetworkModule/Socket/LinuxSocket.h
        NetworkModule/Socket/LinuxSocket.cpp
        Client/AClient.hh
        Client/Client.cpp
        Client/Client.hh
        Exceptions/Exceptions.cpp Exceptions/Exceptions.hh
        ../../Logger/Logger.hpp
        ../../Logger/LoggerConfiguration.cpp
        ../../Logger/LoggerHelper.hpp
        ../HttpReceiver/HttpReceiver/HttpReceiver.cpp
        ../HttpReceiver/HttpReceiver/HttpReceiver.hh
        ../HttpReceiver/HttpHandler.cpp
        ../HttpReceiver/HttpHandler.hh
        )