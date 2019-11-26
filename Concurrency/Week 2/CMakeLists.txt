include_directories(.)

add_executable(Concur_Week2 main.cpp)
target_link_libraries(Concur_Week2 Threads::Threads CONAN_PKG::tbb)

add_executable(Concur_Week2_Tests test.cpp)
target_link_libraries(Concur_Week2_Tests Threads::Threads CONAN_PKG::Catch2 CONAN_PKG::tbb)
target_compile_definitions(Concur_Week2_Tests PUBLIC CATCH_CONFIG_ENABLE_BENCHMARKING)