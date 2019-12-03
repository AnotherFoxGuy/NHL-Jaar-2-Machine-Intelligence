include_directories(.;${CMAKE_SOURCE_DIR}/Threadpool)

add_executable(Concur_Week4 main.cpp GIS_TRI.cpp GIS_TRI.h)
target_link_libraries(Concur_Week4 Threads::Threads CONAN_PKG::tbb)

add_executable(Concur_Week4_Tests test.cpp GIS_TRI.cpp GIS_TRI.h)
target_link_libraries(Concur_Week4_Tests Threads::Threads CONAN_PKG::Catch2 CONAN_PKG::tbb)
target_compile_definitions(Concur_Week4_Tests PUBLIC CATCH_CONFIG_ENABLE_BENCHMARKING)