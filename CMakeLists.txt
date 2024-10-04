cmake_minimum_required(VERSION 3.29)
project(Alpha)

set(CMAKE_CXX_STANDARD 26)

## Directories to include
include_directories(${CMAKE_SOURCE_DIR}/Error
        ${CMAKE_SOURCE_DIR}/Parser
        ${CMAKE_SOURCE_DIR}/Token
        ${CMAKE_SOURCE_DIR}/Lexer
        ${CMAKE_SOURCE_DIR}/Lexer/AST
        ${CMAKE_SOURCE_DIR}/Expression
        ${CMAKE_SOURCE_DIR}/Interpreter)

## Source files
set(SOURCES
        main.cpp
        Parser/Parser.cpp
        Error/Error.cpp
        Lexer/Lexer.cpp
        Expression/Expression.h
        Interpreter/Interpreter.cpp
        Expression/Expression.cpp

)

add_executable(Alpha ${SOURCES})
