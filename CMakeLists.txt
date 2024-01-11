cmake_minimum_required(VERSION 3.10)

project(MultiArrayProject)

set(CMAKE_CXX_STANDARD 20)

# Compilation for variant version
add_executable(MultiArrayVariant
    variant/main-variant.cpp
    variant/class-multi-array-variant.hpp
)

# Compilation for polymorphic version
add_executable(MultiArrayPoly
    polymorphe/main-polymorphe.cpp
    polymorphe/class-multi-array-polymorphe.hpp
)
