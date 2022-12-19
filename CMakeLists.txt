cmake_minimum_required(VERSION 3.23)
project(SSET_APT_House_Vacation_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(class)

add_executable(SSET_APT_House_Vacation_Project
        class/class.cpp
        class/class.h
        class/System.cpp
        class/System.h
        "House Vacation main.cpp")
