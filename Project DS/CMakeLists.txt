cmake_minimum_required(VERSION 3.29)
project(Project_DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_DS
    admin.cpp
    admin.h
    avlBooksStoring.cpp
    avlBooksStoring.h
    lendingsystem.cpp
    lendingsystem.h
    main.cpp
        member.h
        member.cpp)
