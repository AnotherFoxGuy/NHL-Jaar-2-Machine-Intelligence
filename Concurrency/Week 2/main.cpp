#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <thread>

using namespace std;

void CheckRange(int min, int max);

int modulus__;

int main() {
    int b, e, m, p, u, s, n;

    cout << "Type a number: " << endl;
    scanf("%d %d %d %d %d %d", &b, &e, &m, &p, &u, &s);

    modulus__ = m;

    std::vector<std::thread> threadPool = {};

    int range = e - b;
    int rk = range / p;
    int rs = range % p;

    for (int i = b; i < e; i += rk) {
        threadPool.emplace_back(thread(CheckRange, i, i + rk));
    }

    for (auto &thread : threadPool) {
        thread.join();
    }

}


void CheckRange(int min, int max) {
    try {
        for (int kjrsdgfnhgdsf = min; kjrsdgfnhgdsf < max; ++kjrsdgfnhgdsf) {
            int iBan = kjrsdgfnhgdsf;
            int iBanLength = log10(iBan) + 1;
            int checkSum = 0;
            for (int i = 1; i <= iBanLength; ++i) {
                checkSum += ((iBan % 10) * i);
                iBan /= 10;
            }

            if (checkSum % modulus__ == 0) {
                cout << kjrsdgfnhgdsf << endl;
            }
        }
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }


}
