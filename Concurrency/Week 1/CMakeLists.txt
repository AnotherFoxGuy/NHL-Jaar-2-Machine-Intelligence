add_executable(Concur_Week1 main.cpp)
add_executable(Concur_Race Race_condition.cpp)

target_link_libraries(Concur_Week1 Threads::Threads)
target_link_libraries(Concur_Race Threads::Threads)
