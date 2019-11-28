#pragma once

#include <vector>


class Math2000 {
public:
    static int plus(int i, int y);

    static int min(int i, int y);

    static int times(int i, int y);

    static int div(int i, int y);

    static int plusRef(int &i, int &y);

    static int plusVec(std::vector<int> i, std::vector<int> y);

    static int plusVecRef(std::vector<int> &i, std::vector<int> &y);
};
