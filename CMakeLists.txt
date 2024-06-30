cmake_minimum_required(VERSION 3.1)
project(main VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb")
set(CMAKE_CXX_STANDARD 20)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LoremIpsum_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/LoremIpsum)
add_subdirectory(${LoremIpsum_DIR})

message("LoremIpsum:")
message(" + dir:      " ${LoremIpsum_DIR})
message(" + found:    " ${LoremIpsum_FOUND})
message(" + inc:      " ${LoremIpsum_INCLUDES})
message(" + inc dirs: " ${LoremIpsum_INCLUDE_DIRECTORIES})
message(" + libs:     " ${LoremIpsum_LIBS})
message(" + libs:     " ${LoremIpsum_LIBRARIES})


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE LoremIpsum)



# CHECKOUT THIS ASWELL
# https://github.com/robotology/how-to-export-cpp-library/blob/master/src/LibTemplateCMake/CMakeLists.txt
