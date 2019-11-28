//
// Created by anotherfoxguy on 28-11-19.
//

#include <iostream>
#include "Calculator.h"
#include "Math2000.h"

using namespace std;

string Calculator::Calc(string imp) {
    int x = 0, y = 0;
    char c = ' ', res[100];

    sscanf(imp.c_str(), "%d %c %d", &x, &c, &y);

    switch (c) {
        case '+':
            sprintf(res, "%d + %d = %d", x, y, Math2000::plus(x, y));
            break;
        case '-':
            sprintf(res, "%d - %d = %d", x, y, Math2000::min(x, y));
            break;
        case '*':
            sprintf(res, "%d * %d = %d", x, y, Math2000::times(x, y));
            break;
        case '/':
            sprintf(res, "%d / %d = %d", x, y, Math2000::div(x, y));
            break;
        default:
            sprintf(res, "Unknown: %c", c);
    }

    return res;
}