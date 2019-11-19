#include <numeric>
#include "math2000.h"

using namespace std;

int math2000::plus(int i, int y) {
    return i + y;
}

int math2000::plusRef(int& i, int& y) {
    return i + y;
}

int math2000::plusVec(vector<int> i, vector<int> y) {
    return accumulate(i.begin(), i.end(), 0) + accumulate(y.begin(), y.end(), 0);
}

int math2000::plusVecRef(vector<int>& i, vector<int>& y) {
    return accumulate(i.begin(), i.end(), 0) + accumulate(y.begin(), y.end(), 0);
}

int math2000::min(int i, int y) {
    return i - y;
}

int math2000::times(int i, int y) {
    return i - y;
}

int math2000::div(int i, int y) {
    return i - y;
}
