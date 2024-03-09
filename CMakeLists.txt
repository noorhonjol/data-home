cmake_minimum_required(VERSION 3.26)
project(data_home)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_home main.cpp
        Car.cpp
        Car.h
        Vehicle.cpp
        Vehicle.h "Motorcycle.h")
