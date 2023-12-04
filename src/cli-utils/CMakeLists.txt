cmake_minimum_required(VERSION 3.12)
project(CliUtilities)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Add For CLANGD LSP to see local includes properly
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Directory for common headers
include_directories(${CMAKE_SOURCE_DIR}/include)


# List of executables 
set(EXECUTABLES
    exe1
    exe2
    cat
    tail
    win_tail
)


# Create a target for each executable 
foreach(EXE ${EXECUTABLES})
    add_executable(${EXE} src/${EXE}/main.cpp)
endforeach()

set_target_properties(${EXECUTABLE} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)


# Default Build Type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()







