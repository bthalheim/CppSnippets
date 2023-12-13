
cmake_minimum_required(VERSION 3.10)
project(C_TOTP_UTILITY)

# Source Files 
file(GLOB SOURCES "src/*.c")



# Include Directories
include_directories(
    include
    include/ctotp
)


# Create the Executable
add_executable(C_TOTP_UTILITY {$SOURCES})







