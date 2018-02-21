cmake_minimum_required(VERSION 3.5)
project(cpp_zia)

if(APPLE)
    set(CMAKE_CXX_COMPILER g++-7)
endif()

if (NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif()

if (WIN32)
    set(OS_ONLY_FILES
            ConfParser/WindowsDirectoryReader.cpp
            ConfParser/WindowsDirectoryReader.h)
else()
    set(OS_ONLY_FILES
            ConfParser/LinuxDirectoryReader.cpp
            ConfParser/LinuxDirectoryReader.h)
endif()

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
        ${OS_ONLY_FILES}
        )
	

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT cpp_zia)

if (UNIX)
    target_link_libraries(cpp_zia dl pthread)
else()
	target_link_libraries(cpp_zia pthreadVC2)
endif()
