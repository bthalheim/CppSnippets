cmake_minimum_required(VERSION 3.12)

project(DataSerial) 


# Compiler Settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add For CLANGD LSP to see local includes properly
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)


set(SOURCES
    src/main.cpp
    src/MyData.hpp
)

add_executable(DataSerial ${SOURCES})

