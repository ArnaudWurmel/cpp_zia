cmake_minimum_required(VERSION 3.5)
project(cpp_zia)

if(APPLE)
    set(CMAKE_CXX_COMPILER g++-7)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(cpp_zia
        main.cpp
        Logger/Logger.hpp
        Zia/Zia.cpp
        Zia/Zia.hh
        Logger/LoggerHelper.hpp
        Logger/Logger.cpp
        Logger/LoggerConfiguration.cpp
        Logger/LoggerConfiguration.hh
        Zia/ArgParsing/ArgParsing.cpp
        Zia/ArgParsing/ArgParsing.hh
        Zia/Exceptions/Exceptions.cpp
        Zia/Exceptions/Exceptions.h
        ConfParser/AConfParser.h
        ConfParser/ADirectoryReader.cpp
        ConfParser/ADirectoryReader.h
        ConfParser/Configuration.cpp
        ConfParser/Configuration.h
        ConfParser/JsonConfParser.cpp
        ConfParser/JsonConfParser.h
        ConfParser/LinuxDirectoryReader.cpp
        ConfParser/LinuxDirectoryReader.h
        api/http.h
        api/conf.h
        api/net.h
        api/module.h
        Zia/VHostManager/VHostManager.cpp
        Zia/VHostManager/VHostManager.hh
        Zia/VHostManager/VHost.cpp
        Zia/VHostManager/VHost.hh
        Zia/ModuleLoader/Module.hh
        Zia/ModuleLoader/DLLManager/ADLLManager.cpp
        Zia/ModuleLoader/DLLManager/ADLLManager.hh
        Zia/ModuleLoader/DLLManager/LinuxDLLManager.hpp
        Zia/ModuleLoader/DLLManager/WindowsDLLManager.hpp
        )

target_link_libraries(cpp_zia dl)