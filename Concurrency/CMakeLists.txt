cmake_minimum_required(VERSION 3.15)
include(FeatureSummary)
project(ConcurrencyCPP)
set(CMAKE_CXX_STANDARD 17)
find_package (Threads)

add_executable(Week1 Week1.cpp)

target_link_libraries (Week1 Threads::Threads)

feature_summary(WHAT ALL)