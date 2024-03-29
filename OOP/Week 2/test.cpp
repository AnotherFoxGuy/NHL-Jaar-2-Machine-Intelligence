#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "math2000.h"


TEST_CASE("Benchmarks with int", "[Math2000]") {
    int x = 50, y = 60;

    BENCHMARK("Compute speed with ref") {
                                            return Math2000::plusRef(x, y);
                                        };
    BENCHMARK("Compute speed without ref") {
                                               return Math2000::plus(x, y);
                                           };
}

TEST_CASE("Benchmarks with vector", "[Math2000]") {
    std::vector<int> x = {1, 2, 3, 5, 8, 9}
    , y = {9, 54, 24, 64, 71, 14};

    BENCHMARK("Compute speed with ref") {
                                            return Math2000::plusVecRef(x, y);
                                        };
    BENCHMARK("Compute speed without ref") {
                                               return Math2000::plusVec(x, y);
                                           };
}
