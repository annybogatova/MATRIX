cmake_minimum_required(VERSION 3.26)
project(MATRIX)

set(CMAKE_CXX_STANDARD 17)

add_executable(MATRIX main.cpp
        Manager.cpp
        Manager.h
        Line.cpp
        Line.h
        Symbol.cpp
        Symbol.h
        Welcome.cpp
        Welcome.h
        Run.cpp
        Run.h
        Windows.cpp
        Windows.h
        cs.h
        Figure.cpp
        Figure.h
        Explosion.cpp
        Explosion.h)
