cmake_minimum_required(VERSION 3.1)
project(TermWriter VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)

set(TW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc/TW)

set(TW_INCLUDES
    ${TW_INCLUDE_DIR}/TermWriter.hpp
)
    
set(TW_SOURCES
 ${CMAKE_CURRENT_SOURCE_DIR}/src/TermWriter.cpp
)

if(PROJECT_IS_TOP_LEVEL)
    message("====================================")
    message("TermWriter")
    message("---")
    message("Printer with a verbose newline functionality.")
    message("According to our license, you must NEVER use static linking with out library!")
    message("====================================")
endif()

add_library(TW SHARED)
target_sources(TW PRIVATE ${TW_SOURCES})

target_include_directories(TW
  PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/inc"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
