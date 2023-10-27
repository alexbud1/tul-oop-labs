cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/Student.h
        src/Student.cpp
)
#create shared library of type STATIC, SHARED or MODULE using following source files
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)