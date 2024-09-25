cmake_minimum_required(VERSION 3.29)
project(alpha_Interpreter)

set(CMAKE_CXX_STANDARD 26)

add_executable(alpha_Interpreter main.cpp
        tokenizer.cpp
        AST.cpp)
