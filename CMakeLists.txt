cmake_minimum_required(VERSION 3.8)
project(LobachevskyUniversity_HomeWork)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c searchSquareinCircle/searchSquareInCircle.c searchSquareinCircle/searchSquareInCircle.h euclideanAlgorithm/EuclideanAlgorithm.c euclideanAlgorithm/EuclideanAlgorithm.h)
add_executable(LobachevskyUniversity_HomeWork ${SOURCE_FILES})