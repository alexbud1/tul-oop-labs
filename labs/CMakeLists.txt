#Minimal version of cmake required to build this project
cmake_minimum_required(VERSION 3.4)

#Configuration parameters for development platform and compiler flags
set(CMAKE_CXX_COMPILER g++)  #g++ as C++ compiler
set(CMAKE_C_COMPILER gcc)    #gcc as C compiler
set(CMAKE_CXX_STANDARD 11)   #Standard C++11, without this g++ will use its defaults. For g++ since version 6 it is C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)  #Defined above version of C++ standard is required

#Set the Debug profile, maximum level of debug info g3, and format of debug info to dwarf-4 (debugger gdb in version 7 will be required).
#BUILD_TYPE can be set to może być ustawiony na:
#empty,
#Debug,
#Release,
#RelWithDebInfo
#MinSizeRel
#Enable additional flags to generate information for debugger
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g3 -gdwarf-4")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -gdwarf-4")
#Set name of the project and language used to C++
project(OOPProject)
enable_language(CXX)
#In extra file compile_commands.json you can look at all compiler commands with parameters.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)
#Include subproject residing in subdirectory program. Inside this subdirectory the file CMakeLists.txt has to be present there.
add_subdirectory(program)
#Enabling unit tests will add additional target test in Makefile files.
enable_testing()
add_subdirectory(library)