cmake_minimum_required(VERSION 3.15)

project(huiswerk)

include(FeatureSummary)
include(pmm.cmake)
pmm(CMakeCM ROLLING)
include(cotire)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads)


add_subdirectory(Concurrency)
add_subdirectory(OOP)

feature_summary(WHAT ALL)