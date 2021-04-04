project(imgproc)
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING
            "The file conanbuildinfo.cmake doesn't exist, "
            "you have to run 'conan install' in ${CMAKE_BINARY_DIR} first")
endif()

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
