cmake_minimum_required(VERSION 3.1)

#====================================
# User Configuration
#====================================

project(TermWriter VERSION 0.1.0)

# Compilaton Setup
set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb")
set(CMAKE_CXX_STANDARD 20)

# Generate compile_commands.json for clang intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(TW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc/TW)

set(TW_INCLUDES
    ${TW_INCLUDE_DIR}/TermWriter.hpp
)
    
set(TW_SOURCES
 ${CMAKE_CURRENT_SOURCE_DIR}/src/TermWriter.cpp
)

#====================================
# Print Library Information
#====================================

# Print Project info
if(PROJECT_IS_TOP_LEVEL)
    message("")
    message("PROJECT INFO:")
    message("|  name:            " ${PROJECT_NAME})
    message("|  dir:             " ${CMAKE_CURRENT_SOURCE_DIR})
    # message("|  include dir:     " ${LIB_PUBLIC_INCLUDE_DIR})
    # message("|  source dir:      " ${LIB_PRIVATE_SOURCE_DIR})
    # message("|  linked:          " ${LINKED_LIBS})
    # message("___")
endif()

#====================================
# Make Library
#====================================

# Set library target

add_library(TW STATIC)
target_sources(TW PRIVATE ${TW_SOURCES})

target_include_directories(TW
  PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/inc"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
