cmake_minimum_required(VERSION 3.1)
project(LoremIpsum VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)

set(LOREMIPSUM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/LoremIpsum)

set(LOREMIPSUM_INCLUDES
    ${LOREMIPSUM_INCLUDE_DIR}/LoremIpsum.hpp
)
    
set(LOREMIPSUM_SOURCES
 ${CMAKE_CURRENT_SOURCE_DIR}/src/LoremIpsum.cpp
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/TermWriter)

if(PROJECT_IS_TOP_LEVEL)
    message("====================================")
    message("Lorem Ipsum")
    message("---")
    message("A cool lorem ipsum printer that can at most print 3 words in the series.")
    message("Depends on the TermWriter utility (and provides it as a public interface)")
    message("====================================")
endif()

add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PRIVATE ${LOREMIPSUM_SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC TW)

target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
