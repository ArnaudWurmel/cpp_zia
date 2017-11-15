cmake_minimum_required(VERSION 2.6)

if (APPLE)
    set(CMAKE_CXX_COMPILER /usr/bin/g++)
    set(CMAKE_CXX_COMPILER /usr/bin/gcc)
endif(APPLE)


# Project Configuration
project(zia)
set(CMAKE_CXX_STANDARD 11)

# Source files
set(SOURCE_FILES main.cpp ConfParser/Configuration.cpp ConfParser/Configuration.h Logger/Logger.h ConfParser/AConfParser.h ConfParser/JsonConfParser.cpp ConfParser/JsonConfParser.h lib/json.hpp Exceptions/Exceptions.cpp Exceptions/Exceptions.h VirtualHostManager/VirtualHostManager.cpp VirtualHostManager/VirtualHostManager.h VirtualHostManager/VHost.cpp VirtualHostManager/VHost.h ConfParser/ADirectoryReader.h ConfParser/LinuxDirectoryReader.cpp ConfParser/LinuxDirectoryReader.cpp ConfParser/LinuxDirectoryReader.h ConfParser/ADirectoryReader.cpp VirtualHostManager/Socket/ISocket.h VirtualHostManager/Socket/ISocketAcceptor.h VirtualHostManager/Socket/LinuxAcceptor.cpp VirtualHostManager/Socket/LinuxAcceptor.h VirtualHostManager/Socket/ISocketAcceptor.cpp VirtualHostManager/Socket/LinuxSocket.cpp VirtualHostManager/Socket/LinuxSocket.h Client/AClient.hh Client/Client.cpp Client/Client.hh Module/AModule.hpp Module/IClient.hpp Module/IHttpBase.hpp Module/IHttpRequest.hpp Module/IHttpResponse.h)

include_directories(
        ./lib
)

# Executable declaration
add_executable(
    zia
    ${SOURCE_FILES}
)

# Windows
if (WIN32)
    macro(get_WIN32_WINNT version)
        if (CMAKE_SYSTEM_VERSION)
            set(ver ${CMAKE_SYSTEM_VERSION})
            string(REGEX MATCH "^([0-9]+).([0-9])" ver ${ver})
            string(REGEX MATCH "^([0-9]+)" verMajor ${ver})
            # Check for Windows 10, b/c we'll need to convert to hex 'A'.
            if ("${verMajor}" MATCHES "10")
                set(verMajor "A")
                string(REGEX REPLACE "^([0-9]+)" ${verMajor} ver ${ver})
            endif ("${verMajor}" MATCHES "10")
            # Remove all remaining '.' characters.
            string(REPLACE "." "" ver ${ver})
            # Prepend each digit with a zero.
            string(REGEX REPLACE "([0-9A-Z])" "0\\1" ver ${ver})
            set(${version} "0x${ver}")
        endif(CMAKE_SYSTEM_VERSION)
    endmacro(get_WIN32_WINNT)

    get_WIN32_WINNT(ver)
    add_definitions(-D_WIN32_WINNT=${ver})
endif(WIN32)

if (WIN32)
	target_compile_options(
		zia PRIVATE
		"/EHsc"
	)
endif(WIN32)
target_link_libraries(zia pthread)
