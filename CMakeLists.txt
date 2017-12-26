cmake_minimum_required(VERSION 3.9)
project(cpp_zia)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_zia main.cpp Logger/Logger.hpp Zia/Zia.cpp Zia/Zia.hh Logger/LoggerHelper.hpp Logger/Logger.cpp Logger/LoggerConfiguration.cpp Logger/LoggerConfiguration.hh Zia/ArgParsing/ArgParsing.cpp Zia/ArgParsing/ArgParsing.hh Zia/Exceptions/Exceptions.cpp Zia/Exceptions/Exceptions.h ConfParser/AConfParser.h ConfParser/ADirectoryReader.cpp ConfParser/ADirectoryReader.h ConfParser/Configuration.cpp ConfParser/Configuration.h ConfParser/JsonConfParser.cpp ConfParser/JsonConfParser.h ConfParser/LinuxDirectoryReader.cpp ConfParser/LinuxDirectoryReader.h api/http.h api/conf.h api/net.h api/module.h)