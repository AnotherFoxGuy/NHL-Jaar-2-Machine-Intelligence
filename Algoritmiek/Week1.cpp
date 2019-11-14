#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> getNames();

vector<string> MergeSort(vector<string> list);


int main() {
    vector<string> namessort = MergeSort(getNames());

    for (auto & i : namessort) {
        // cout << names[i] << endl;
        printf("Name: %s\n", i.c_str());
    }
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
