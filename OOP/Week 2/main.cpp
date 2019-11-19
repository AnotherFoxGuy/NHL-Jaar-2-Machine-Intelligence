#include <iostream>
#include <string>
#include <chrono>
#include "math2000.h"

using namespace std;

int main() {
    int x = 0, y = 0;
    char c = ' ';
    cout << "Type a number: " << endl;
    cin >> x;
    cout << "Type a math operator: " << endl;
    cin >> c;
    cout << "Type the next number: " << endl;
    cin >> y;

    switch (c) {
        case '+':
            printf("%d + %d = %d", x, y, math2000::plus(x, y));
            break;
        case '-':
            printf("%d - %d = %d", x, y, math2000::min(x, y));
            break;
        case '*':
            printf("%d * %d = %d", x, y, math2000::times(x, y));
            break;
        case '/':
            printf("%d / %d = %d", x, y, math2000::div(x, y));
            break;
        default:
            cout << "Unrec: " << c << endl;
    }



}
