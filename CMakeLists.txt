cmake_minimum_required(VERSION 3.29)
project(alpha_Interpreter)

set(CMAKE_CXX_STANDARD 26)

set(SOURCES
    main.cpp
        Token/Token.cpp
        Token/Token.h
        Token/TokenType.h
        Interpreter/Interpreter.cpp
        Interpreter/Interpreter.h)

add_executable(alpha_Interpreter ${SOURCES}
)
