#include <iostream>
#include "lib_rational.h"
#include "rational_poly.h"

using std::cout;
using std::endl;

int main() {
    std::cout << "Hello, World!" << std::endl;
    lib_rational r1(-2, 3);
    lib_rational r2(4, 8);
    lib_rational r0 = r1 * r2;
    cout << r0 << endl;
    cout << r2 * r1 << endl;
    cout << r1 / r2 << endl;
    cout << r1 - r2 << endl;
    cout << r2 - r1 << endl;
    cout << (r1 < r2) << endl;
    cout << (r1 > r2) << endl;
    cout << r1.pow(3) << endl;
    cout << r1 << endl;
    cout << endl;

    rational_poly pol;
    pol.addFactor({1, 1});
    pol.addFactor({0, 2});
    pol.addFactor({1, -4});
    cout << pol.eval({1, 1}) << endl;
    pol.calculateLargest({1, 2}, {1, -2});


    return 0;
}