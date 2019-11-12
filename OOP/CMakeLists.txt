cmake_minimum_required(VERSION 3.15)

include(FeatureSummary)
include(../pmm.cmake)
pmm(CMakeCM ROLLING)
include(cotire)

project(OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Week1 Opdracht_Week_1.cpp)
cotire(Week1)