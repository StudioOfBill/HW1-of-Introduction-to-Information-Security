cmake_minimum_required(VERSION 3.6)
project(monoalphabetic_cipher)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Key.txt
        cmake-build-debug/Makefile
        cmake-build-debug/monoalphabetic_cipher.cbp
        cmake-build-debug/Plaintext.txt
        CMakeLists.txt
        main.cpp)

add_executable(monoalphabetic_cipher ${SOURCE_FILES})