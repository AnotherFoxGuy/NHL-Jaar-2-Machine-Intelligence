cmake_minimum_required(VERSION 3.15)
include(FeatureSummary)
project(ConcurrencyCPP)
set(CMAKE_CXX_STANDARD 17)
find_package (Threads)

add_executable(ConcurrencyCPP main.cpp)

target_link_libraries (ConcurrencyCPP Threads::Threads)

feature_summary(WHAT ALL)