cmake_minimum_required(VERSION 3.6)
project(playfair_cipher)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/playfair_cipher
        cmake-build-debug/playfair_cipher.cbp
        CMakeLists.txt
        main.cpp)

add_executable(playfair_cipher ${SOURCE_FILES})