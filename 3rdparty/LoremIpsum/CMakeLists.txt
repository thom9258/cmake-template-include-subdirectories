cmake_minimum_required(VERSION 3.1)

#====================================
# User Configuration
#====================================

project(LoremIpsum VERSION 0.1.0)

# Compilaton Setup
set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb")
set(CMAKE_CXX_STANDARD 20)

# Generate compile_commands.json for clang intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LOREMIPSUM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/LoremIpsum)

set(LOREMIPSUM_INCLUDES
    ${LOREMIPSUM_INCLUDE_DIR}/LoremIpsum.hpp
)
    
set(LOREMIPSUM_SOURCES
 ${CMAKE_CURRENT_SOURCE_DIR}/src/LoremIpsum.cpp
)

set(TW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/TermWriter)
add_subdirectory(${TW_DIR})

message("LoremIpsum links with TermWriter")
message("Dir " ${TW_DIR})


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

add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PRIVATE ${LOREMIPSUM_SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC TW)

message(":")

# Exporting include directory:
# https://cmake.org/cmake/help/latest/guide/importing-exporting/index.html
target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
