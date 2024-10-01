cmake_minimum_required(VERSION 3.29)
project(Alpha)

set(CMAKE_CXX_STANDARD 26)

##directories to include
include_directories(${CMAKE_SOURCE_DIR}/Error
                    ${CMAKE_SOURCE_DIR}/Interpreter
                    ${CMAKE_SOURCE_DIR}/Token)

##source files
set(SOURCES
        main.cpp
        Interpreter/Interpreter.cpp
        Error/Error.cpp
        Lexer/Lexer.cpp
        Lexer/Lexer.h)

add_executable(Alpha ${SOURCES})
