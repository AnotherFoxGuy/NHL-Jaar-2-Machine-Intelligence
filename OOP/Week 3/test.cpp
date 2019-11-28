#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "Calculator.h"


TEST_CASE("Calculator tests", "[Calculator]") {
    auto c = new Calculator();
    REQUIRE(c->Calc("1 + 1") == "1 + 1 = 2" );
    REQUIRE(c->Calc("5 - 1") == "5 - 1 = 4" );
    REQUIRE(c->Calc("2 * 2") == "2 * 2 = 4" );
    REQUIRE(c->Calc("6 / 2") == "6 / 2 = 3" );
}

TEST_CASE("Calculator imp tests", "[Calculator]") {
    auto c = new Calculator();
    REQUIRE(c->Calc("1 + 1") == "1 + 1 = 2" );
    REQUIRE(c->Calc("1+1") == "1 + 1 = 2" );
    REQUIRE(c->Calc("Kaas") == "Unknown:  " );
}