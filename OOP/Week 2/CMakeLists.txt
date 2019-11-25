include_directories(.)

add_executable(OOP_Calculator main.cpp math2000.cpp)
add_executable(OOP_CalculatorTests test.cpp math2000.cpp)

target_compile_definitions(OOP_CalculatorTests PUBLIC CATCH_CONFIG_ENABLE_BENCHMARKING)
target_link_libraries(OOP_CalculatorTests PUBLIC CONAN_PKG::Catch2)

#cotire(OOP_CalculatorTests)