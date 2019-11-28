#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

int main() {
    cout << "Type a number: " << endl;

    string dat;
    getline(cin, dat);

    auto c = new Calculator();

    cout << c->Calc(dat);
}
