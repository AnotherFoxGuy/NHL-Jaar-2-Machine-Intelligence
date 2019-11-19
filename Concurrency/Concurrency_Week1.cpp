#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>

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

void keep_promise_too(promise<int>&& promise_obj){
    promise_obj.set_value(rand());
}

void op6() {
//Alternatively with a promise object:​
    promise<int> promise_obj;

    future<int> result = promise_obj.get_future();
    thread t(keep_promise_too, std::move(promise_obj));

    result.wait();
    printf("%d\n", result.get());

    t.join();
}


int main() {
    op6();
    cout << "Hello, World! \n" << endl;
    return 0;
}