#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <thread>
#include <mutex>
#include <csignal>
#include <unistd.h>

#include <tbb/task_group.h>
#include "GIS_TRI.h"


using namespace std;


void PrintGrid(vector<vector<int>> res){
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    int v_size = 10;
    vector<vector<int>> dat(v_size, vector<int> (v_size, 0));

    for (int y = 0; y < v_size; y++)
        for (int x = 0; x < v_size; x++)
            dat[x][y] = rand() % 100;

    auto cc = new GIS_TRI();


    auto res = cc->CalculateHeightTrisConcur(dat);

    cout << "imp" << endl;

    PrintGrid(dat);

    cout << endl<< "res" << endl;

    PrintGrid(res);

}
