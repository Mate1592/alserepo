cmake_minimum_required(VERSION 3.10)

project(BibliotecaProject)

# Set standard C++ version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(biblioteca ${SOURCES})
