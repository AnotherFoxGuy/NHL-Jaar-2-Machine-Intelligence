include_directories(.)

add_executable(OOP_CalculatorV2 main.cpp Math2000.cpp Calculator.cpp)
add_executable(OOP_CalculatorV2Tests test.cpp Math2000.cpp Calculator.cpp)

target_link_libraries(OOP_CalculatorV2Tests PUBLIC CONAN_PKG::Catch2)