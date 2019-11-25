include_directories(.)

add_executable(Concur_Week2 main.cpp IBAN_Calc.cpp IBAN_Calc.h)
add_executable(Concur_Week2Tests test.cpp IBAN_Calc.cpp IBAN_Calc.h)

target_compile_definitions(Concur_Week2Tests PUBLIC CATCH_CONFIG_ENABLE_BENCHMARKING)
target_link_libraries(Concur_Week2Tests PUBLIC CONAN_PKG::Catch2 Threads::Threads)

target_link_libraries(Concur_Week2 Threads::Threads)

#cotire(OOP_CalculatorTests)