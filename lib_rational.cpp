

#include "lib_rational.h"
#include <cmath>

void lib_rational::reduse() {
    int gcd = mGetGCD(mNumerator, mDenominator);
    mNumerator /= gcd;
    mDenominator /= gcd;
}

void lib_rational::mTypify() {
    if (mNumerator * (long) mDenominator < 0) {
        mSign = -1;
        mDenominator = abs(mDenominator);
        mNumerator = abs(mNumerator);
    } else {
        mSign = 1;
    }
}

int lib_rational::mGetGCD(int x, int y) {
    if (x == 0 || y == 0) return 1;
    while (x != y)
        if (x > y)
            x = x - y;
        else y = y - x;
    return x;
}

lib_rational lib_rational::operator+(lib_rational const &second) const {
    int numerator = mNumerator + second.mNumerator;
    int denominator = mDenominator + second.mDenominator;
    return {numerator, denominator};
}

lib_rational::lib_rational(int mNumerator, int mDenominator) : mNumerator(mNumerator), mDenominator(mDenominator) {
    mTypify();
    reduse();
}

lib_rational lib_rational::operator-(lib_rational const &) const {
    return lib_rational(0, 0);
}
