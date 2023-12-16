
cmake_minimum_required(VERSION 3.10)
project(C_CURSES_HW)

# Source Files 
file(GLOB SOURCES "src/*.c")


# Add For CLANGD LSP to see local includes properly
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Add nCurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})



# Include Directories
include_directories(
    include
)


# Create the Executable
add_executable(C_CURSES_HW ${SOURCES})

target_link_libraries(C_CURSES_HW ${CURSES_LIBRARIES})





