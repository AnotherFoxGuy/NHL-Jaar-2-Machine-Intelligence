#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "tbb/task_group.h"

using namespace std;

vector<string> getNames();

vector<string> MergeSort(vector<string> list);
vector<string> MergeSortMT(vector<string> list);



TEST_CASE("MergeSort", "[MergeSort]") {

    BENCHMARK("No TBB") {
        return MergeSort(getNames());
    };
    BENCHMARK("TBB") {
        return MergeSortMT(getNames());
    };
}


/// <summary>
/// merges two sorted lists into one sorted list
/// </summary>
/// <param name="a">sorted list</param>
/// <param name="b">sorted list</param>
/// <returns>sorted list</returns>
vector<string> Merge(vector<string> a, vector<string> b) {
    if (a.empty())
        return b;
    if (b.empty())
        return a;

    vector<string> li = {};

    auto ai = a[0];
    auto bi = b[0];

    if (ai < bi) {
        li.emplace_back(ai);
        a.erase(a.begin());
    } else {
        li.emplace_back(bi);
        b.erase(b.begin());
    }

    auto kaas = Merge(a, b);
    li.insert(li.end(), kaas.begin(), kaas.end());
    return li;
}

/// <summary>
/// Sorts a list of integers by using merge
/// </summary>
/// <param name="list">unsorted list</param>
/// <returns>sorted list</returns>
vector<string> MergeSort(vector<string> list) {
    return list.size() <= 1 ? list : Merge(MergeSort(vector<string>(list.begin(), list.begin() + (list.size() / 2))),
                                           MergeSort(vector<string>(list.begin() + (list.size() / 2), list.end())));
}

/// <summary>
/// Sorts a list of integers by using merge
/// </summary>
/// <param name="list">unsorted list</param>
/// <returns>sorted list</returns>
vector<string> MergeSortMT(vector<string> list) {
    vector<string> left(list.begin(), list.begin() + list.size() / 2);
    vector<string> right(list.begin() + list.size() / 2, list.end());

    if (list.size() <= 1) {
        return list;
    } else {
        vector<string> l, r;

        tbb::task_group g;
        g.run([&] { l = MergeSortMT(left); }); // spawn a task
        g.run([&] { r = MergeSortMT(right); }); // spawn another task
        g.wait();                // wait for both tasks to complete

        return Merge(l, r);
    }
}


vector<string> getNames() {
    return {
            "Bjorn",
            "Henk",
            "Willem",
            "Cedric",
            "Cheniqua",
            "Chantal",
            "Patricia",
            "JanRoderikWillemFriso",
            "Hans",
            "Heinrich",
            "Flip",
            "Edgar"
    };
}
