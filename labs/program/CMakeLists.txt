cmake_minimum_required(VERSION 3.4)

project(Program)

#Store in a local variable SOURCE_FILES set of project's source files
set(SOURCE_FILES
        src/main.cpp
)
#Use above set of files to build executable file Program
add_executable(Program ${SOURCE_FILES})
target_link_libraries(Program Library)
#Specify include directory of Program subproject to global list.
#Thanks to this all other subprojects will be able to "see" this directory.
target_include_directories(Program PUBLIC include)