cmake_minimum_required(VERSION 4.2)
project(assigment5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assigment5
        Functions.cpp
        Functions.h
        main.cpp
        Program.cpp
        Program.h
        Tokenization.cpp
        Tokenization.h
        ValuableContainer.cpp
        ValuableContainer.h
        Parser.cpp
        Parser.h)
