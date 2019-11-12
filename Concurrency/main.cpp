#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex mtx;

void printKoekjes(int i) {
    //std::this_thread::sleep_for(std::chrono::milliseconds(20 - i));
    mtx.lock();
    printf("\nint i = %d\n", i);
    mtx.unlock();
}


void op1() {
    int i = 5;
    thread thread_object(printKoekjes, i);
    thread_object.join();
}

void op2() {
    vector<thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(thread(printKoekjes, i));
    }

    for (auto &thread : threads) {
        thread.join();
    }
}


void op3() {

}


int main() {

    //op2();
    cout << "Hello, World! \n" << endl;
    return 0;
}