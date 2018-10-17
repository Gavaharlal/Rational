

#include "rational_poly.h"

using std::cout;
using std::endl;

rational_poly::rational_poly(vector<lib_rational> const &pol) {
    for (const auto &i : pol) {
        mPolynomial.push_back(i);
    }
}

void rational_poly::addFactor(lib_rational const &factor) {
    mPolynomial.push_back(factor);
}

lib_rational rational_poly::eval(lib_rational const &value) {
    lib_rational result = mPolynomial.back();
    for (int i = mPolynomial.size() - 2; i >= 0; --i) {
        result = result * value + mPolynomial[i];
    }
    return result;
}

void rational_poly::calculateLargest(lib_rational const &val1, lib_rational const &val2) {
    lib_rational r1 = eval(val1);
    lib_rational r2 = eval(val2);
    if (r1 == r2) {
        cout << "P(" << val1 << ")" << " = " << "P(" << val2 << ")" << endl;
    } else if (r1 < r2){
        cout << "P(" << val1 << ")" << " < " << "P(" << val2 << ")" << endl;
    } else {
        cout << "P(" << val1 << ")" << " > " << "P(" << val2 << ")" << endl;
    }
}

rational_poly::rational_poly() = default;
