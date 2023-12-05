# Project 
cmake_minimum_required(VERSION 3.14)
project(sqlite-hw)


# Compiler 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Add For CLANGD LSP to see local includes properly
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# Dependancies 
include(FetchContent)

## Fetch SQLite
FetchContent_Declare(
    SQLite
    GIT_REPOSITORY https://github.com/sqlite/sqlite.git
    GIT_TAG version-3.44.2
)


FetchContent_GetProperties(SQLite)


if(NOT SQLite_POPULATED)
    FetchContent_Populate(SQLite)

    add_library(sqlite3 STATIC ${SQLite_SOURCE_DIR}/sqlite3.c)
    target_include_directories(sqlite3 PUBLIC ${SQLite_SOURCE_DIR})
endif()




# Your main executable target
add_executable(sqlite-hw main.cpp)




# Link SQLite to your executable
target_link_libraries(sqlite-hw PRIVATE slqite3)








