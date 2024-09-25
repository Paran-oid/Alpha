cmake_minimum_required(VERSION 3.29)
project(alpha_Interpreter)

set(CMAKE_CXX_STANDARD 26)

#we add all our include directories
include_directories(
        ${CMAKE_SOURCE_DIR}/Token
)

#we add our libraries
add_library(Token ${CMAKE_SOURCE_DIR}/Token/tokenizer.cpp)

set(SOURCES
    main.cpp)

# we set all our sources
add_executable(alpha_Interpreter ${SOURCES}
)

target_link_libraries(alpha_Interpreter Token)