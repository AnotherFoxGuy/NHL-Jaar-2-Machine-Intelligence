cmake_minimum_required(VERSION 3.15)

project(huiswerk)

include(FeatureSummary)
include(pmm.cmake)
pmm(CONAN CMakeCM ROLLING)
include(cotire)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_USE_RELATIVE_PATHS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(Threads)

add_subdirectory(Algoritmiek)
add_subdirectory(Concurrency)
add_subdirectory(OOP)

feature_summary(WHAT ALL)