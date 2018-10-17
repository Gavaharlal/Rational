#include <iostream>
#include "lib_rational.h"

using std::cout;
using std::endl;

int main() {
    std::cout << "Hello, World!" << std::endl;
    lib_rational r1(2, 3);
    lib_rational r2(4, 8);
    lib_rational r0 = r1 * r2;
    cout << r0 << endl;
    cout << r1 / r2 << endl;
    cout << r1 - r2 << endl;
    return 0;
}