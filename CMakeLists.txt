cmake_minimum_required(VERSION 3.29)
project(Alpha)

set(CMAKE_CXX_STANDARD 26)

add_executable(Alpha main.cpp
        Interpreter/Interpreter.cpp
        Interpreter/Interpreter.h
        Token/TokenType.h
        Token/Token.h)
