#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <string>
#include <vector>

#include "GIS_TRI.h"

using namespace std;

TEST_CASE("CalculateHeightTris", "[GIS_TRI]") {
    int v_size = 1000;
    vector<vector<int>> dat(v_size, vector<int> (v_size, 0));

    for (int y = 0; y < v_size; y++)
        for (int x = 0; x < v_size; x++)
            dat[x][y] = rand() % 100;


    auto cc = new GIS_TRI();

    BENCHMARK("Plain") {
                           return cc->CalculateHeightTris(dat);
                       };
    BENCHMARK("TBB") {
                         return cc->CalculateHeightTrisConcur(dat);
                     };

    BENCHMARK("ThreadPool") {
                         return cc->CalculateHeightTrisConcurTP(dat);
                     };
}
