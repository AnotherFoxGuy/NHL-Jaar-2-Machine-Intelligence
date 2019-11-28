#include <iostream>
#include <string>
#include "math2000.h"

using namespace std;

int main() {
    int x = 0, y = 0;
    char c = ' ';

    cout << "Type a number: " << endl;
    scanf("%d %c %d", &x, &c, &y);

    switch (c) {
        case '+':
            printf("%d + %d = %d", x, y, Math2000::plus(x, y));
            break;
        case '-':
            printf("%d - %d = %d", x, y, Math2000::min(x, y));
            break;
        case '*':
            printf("%d * %d = %d", x, y, Math2000::times(x, y));
            break;
        case '/':
            printf("%d / %d = %d", x, y, Math2000::div(x, y));
            break;
        default:
            cout << "Unrec: " << c << endl;
    }
}
