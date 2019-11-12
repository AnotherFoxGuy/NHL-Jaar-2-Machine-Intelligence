// Race_condition.cpp
//

#include <iostream>
#include <random>
#include <vector>
#include <thread>
#include <string>
#include <mutex>
#include <atomic>


#define KAAS 1

std::random_device rd;

std::vector<int> numbers;

std::mutex mtx;

#if !KAAS
std::atomic<int> sum = 0;
#else
int sum = 0;
#endif

void partial_sum(int L, int R) {
#if KAAS
    mtx.lock();
    for (int i = L; i < R; ++i) {
        sum += numbers.at(i);
    }
    mtx.unlock();
#else
    for (int i = L; i < R; ++i)
    {
        sum += numbers.at(i);
    }
#endif
}


int main() {
    int numCount = 10000;
    std::uniform_int_distribution<int> dist(0, 9);
    for (int i = 0; i < numCount; i++) {
        numbers.push_back(dist(rd));
    }


    std::vector<std::thread> threads;

    int numThreads = std::thread::hardware_concurrency();
    int length = numbers.size();

    int delta = length / numThreads;
    int remainder = length % numThreads;
    int L = 0, R = 0;

    for (int i = 0; i < numThreads; i++) {
        R = L + delta;
        if (i == numThreads - 1)
            R += remainder;

        threads.push_back(std::thread(partial_sum, L, R));
        L = R;
    }

    for (auto &t : threads) {
        t.join();
    }

    int sum_correct = 0;

    for (int i = 0; i < numbers.size(); i++) {
        sum_correct += numbers.at(i);
    }


    std::cout << "Concurrent sum is: " << std::to_string(sum) << std::endl << "correct answer is: "
              << std::to_string(sum_correct) << std::endl;
}
