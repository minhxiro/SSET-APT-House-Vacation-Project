cmake_minimum_required(VERSION 3.23)
project(SSET_APT_House_Vacation_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(SystemClass)

add_executable(SSET_APT_House_Vacation_Project
        class/Class.h
        class/Class.cpp
        SystemClass/System.cpp
        SystemClass/System.h
        "main.cpp")
