#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <thread>
#include <mutex>
#include <csignal>
#include <unistd.h>

#define TBB

#ifdef TBB
#include <tbb/task_group.h>
#endif


using namespace std;

void CheckRange(int min, int max);

int modulus__, pdi, Kaas, Koekjes;

mutex mtx;
std::vector<std::thread> threadPool = {};

// 0 374756170 374856250 11 10 1 0
int main() {
    pdi = getpid();

    int b, e, m, p, u, s;

    cout << "Type Data ";
    scanf("%*d %d %d %d %d %d %d", &b, &e, &m, &p, &u, &s);

    modulus__ = m;
    Koekjes = u;

    int range = e - b;
    int rk = range / p;
    int rs = range % p;

#ifndef TBB
    for (int i = b; i < e; i += rk) {
        threadPool.emplace_back(thread(CheckRange, i, i + rk));
    }

    for (auto &thread : threadPool) {
        thread.join();
    }
#else
    tbb::task_group g;

    for (int i = b; i < e; i += rk) {
        g.run([=] { CheckRange(i, i + rk); });
    }

    g.wait();
#endif

    if (u == 0)
        printf("%d", Kaas);

}


void CheckRange(int min, int max) {
    for (int kjrsdgfnhgdsf = min; kjrsdgfnhgdsf < max; ++kjrsdgfnhgdsf) {
        int iBan = kjrsdgfnhgdsf;
        int iBanLength = log10(iBan) + 1;
        int checkSum = 0;
        for (int i = 1; i <= iBanLength; ++i) {
            checkSum += ((iBan % 10) * i);
            iBan /= 10;
        }

        if (checkSum % modulus__ == 0) {
            std::scoped_lock lock(mtx);
            Kaas++;
            if (Koekjes != 0)
                printf("%d %d\n", Kaas, kjrsdgfnhgdsf);
            if (Koekjes == 2 && pdi > 0)
                kill(pdi, 9);
        }
    }
}
