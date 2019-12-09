#pragma once

#include <array>
#include <vector>


class GIS_TRI {
    static int cal(int x, int y);

    int row, collum;

public:
    std::vector<std::vector<int>> data;

    std::vector<std::vector<int>> CalculateHeightTris(std::vector<std::vector<int>>in);

    std::vector<std::vector<int>> CalculateHeightTrisConcur(std::vector<std::vector<int>> in);

    std::vector<std::vector<int>> CalculateHeightTrisConcurTP(std::vector<std::vector<int>> in);
};



