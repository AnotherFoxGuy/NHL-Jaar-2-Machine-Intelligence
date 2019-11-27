/*
    Spawning threads is a very expensive operation. We can optimize this by spawning a number of threads beforehand and re-using these.
    The given class is an example so you can see the internal workings, there is also
*/

#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <deque>

#include "ThreadPool.h"

int test()
{
    return 0;
}

int testV(int val)
{
    return val;
}

int main()
{
    int threadCount = std::thread::hardware_concurrency();
    ThreadPool pool(8);

    //Spawn a few threads
    for (int i = 0; i < 16; i++)
    {
        pool.enqueue([i]() { std::cout << "Hello from thread " << i << std::endl; });
    }

    //Enqueue 2 lambda functions, with future type, or for simplicity auto
    std::future<int> func1 = pool.enqueue([] {return 1; });
    auto func2 = pool.enqueue([] {return 2; });

    std::cout << (func1.get()) + (func2.get()) << std::endl;

    //Enqueue function
    std::future<int> testFuture = pool.enqueue(test);
    int testReturn = testFuture.get();

    int newValue = 1000;

    //Enqueue without return value
    std::future<void> testVoid = pool.enqueue([] { return; });

    testVoid.wait();

    //Enqueue with parameter
    std::future<int> testFuture2 = pool.enqueue([&]
    { 
        return testV(newValue); 
    });
    testReturn = testFuture2.get();


    // wait for keypress to give worker threads the opportunity to finish tasks
    std::cin.ignore();

}