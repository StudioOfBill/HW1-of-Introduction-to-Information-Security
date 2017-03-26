cmake_minimum_required(VERSION 3.6)
project(vernam_proposed_the_autokey_system)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/vernam_proposed_the_autokey_system.cbp
        CMakeLists.txt
        main.cpp)

add_executable(vernam_proposed_the_autokey_system ${SOURCE_FILES})