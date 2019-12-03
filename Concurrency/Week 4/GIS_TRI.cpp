#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include <mutex>
#include <cmath>
#include "GIS_TRI.h"


using namespace std;
using namespace tbb;


int GIS_TRI::cal(int x, int y) {
    return pow(x - y, 2);
}

vector<vector<int>> GIS_TRI::CalculateHeightTris(vector<vector<int>> in) {
    vector<vector<int>> res(in.size(), vector<int>(in[0].size(), 0));

    for (int y = 1; y < (in.size() - 1); ++y)
        for (int x = 1; x < (in[y].size() - 1); ++x) {

            int r = 0;

            r += cal(in[x][y], in[x - 1][y + 1]);
            r += cal(in[x][y], in[x][y + 1]);
            r += cal(in[x][y], in[x + 1][y + 1]);
            r += cal(in[x][y], in[x + 1][y]);
            r += cal(in[x][y], in[x + 1][y - 1]);
            r += cal(in[x][y], in[x][y - 1]);
            r += cal(in[x][y], in[x - 1][y - 1]);
            r += cal(in[x][y], in[x - 1][y]);

            res[x][y] = sqrt(r);
        }
    return res;
}

vector<vector<int>> GIS_TRI::CalculateHeightTrisConcur(vector<vector<int>> in) {
    vector<vector<int>> res(in.size(), vector<int>(in[0].size(), 0));

    parallel_for(blocked_range<int>(1, in.size() - 1),
                      [&](blocked_range<int> r) {
                          for (int y = r.begin(); y < r.end(); ++y)
                              for (int x = 1; x < (in[y].size() - 1); ++x) {
                                  int re = 0;

                                  re += cal(in[x][y], in[x - 1][y + 1]);
                                  re += cal(in[x][y], in[x][y + 1]);
                                  re += cal(in[x][y], in[x + 1][y + 1]);
                                  re += cal(in[x][y], in[x + 1][y]);
                                  re += cal(in[x][y], in[x + 1][y - 1]);
                                  re += cal(in[x][y], in[x][y - 1]);
                                  re += cal(in[x][y], in[x - 1][y - 1]);
                                  re += cal(in[x][y], in[x - 1][y]);

                                  res[x][y] = sqrt(re);
                              }

                      });
    return res;
}





