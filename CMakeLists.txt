cmake_minimum_required(VERSION 3.2)
project(Riptide)

# set default build directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/linux_x86)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/linux_x86)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/linux_x86)

# TODO: how to control debug builds - and compiler optimisations
# compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++0x -Wall -Wno-varargs -fPIC")

# set general libraries include directories
include_directories(
    ${INCLUDE_DIRECTORIES}
    /usr/include/python3.5
    # TODO: eventually replace with proper install paths
    ${CMAKE_BINARY_DIR}/../../ArcaneCore/ArcaneCore/src/cpp
    ${CMAKE_BINARY_DIR}/../../ArcaneLog/ArcaneLog/src/cpp
    ${CMAKE_BINARY_DIR}/../../MetaEngine/MetaEngine/src/cpp
)
# set general libraries link directories
link_directories(
    ${LINK_DIRECTORIES}
    /usr/lib/python3.5/
    # TODO: eventually replace with proper library paths
    ${CMAKE_BINARY_DIR}/../../ArcaneCore/ArcaneCore/build/linux_x86
    ${CMAKE_BINARY_DIR}/../../ArcaneLog/ArcaneLog/build/linux_x86
    ${CMAKE_BINARY_DIR}/../../MetaEngine/MetaEngine/build/linux_x86
)

# build tests
add_subdirectory(tests)