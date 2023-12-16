# Project 
cmake_minimum_required(VERSION 3.14)
project(sqlite-hw)


# Compiler 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Add For CLANGD LSP to see local includes properly
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Set the path to Vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "")


set(VCPKG_TARGET_TRIPLET x64-windows CACHE STRING "")

find_package(sqlite3 CONFIG REQUIRED)


set(SOURCES
    src/main.cpp
)

# Your main executable target
add_executable(sqlite-hw ${SOURCES})


# Link SQLite to your executable
target_link_libraries(sqlite-hw PRIVATE slqite3::sqlite3)







