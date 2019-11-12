cmake_minimum_required(VERSION 3.15)


include(FeatureSummary)
include(../pmm.cmake)
pmm(CMakeCM ROLLING)
include(cotire)

project(ConcurrencyCPP)
set(CMAKE_CXX_STANDARD 17)
find_package(Threads)

add_executable(Week1 Week1.cpp)
add_executable(Race Race_condition/Race_condition.cpp)

target_link_libraries(Week1 Threads::Threads)
target_link_libraries(Race Threads::Threads)

cotire(Week1)
cotire(Race)

feature_summary(WHAT ALL)