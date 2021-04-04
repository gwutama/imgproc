project(learn-image-processing)
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(tests)
