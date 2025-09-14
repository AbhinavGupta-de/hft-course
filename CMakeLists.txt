cmake_minimum_required(VERSION 4.0)
project(basics)

set(CMAKE_CXX_STANDARD 26)

add_executable(basics main.cpp
        main.cpp
        lec2/marketOrder.cpp
        lec2/swapExercise.cpp
        lec3/advancedPtr.cpp
        lec4/arraysPtr.cpp
        lec4/Thousandnodes.cpp
        lec5/memoryPool.cpp
        lec6/templates.cpp
        lec6/templateSpecializations.cpp
        lec6/factorialMetaProgramming.cpp
        lec6/fibonacciMetaProgramming.cpp
        lec6/gcdMetaprogramming.cpp
        lec6/inheritance.cpp)
