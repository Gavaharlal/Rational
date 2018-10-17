

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

int lib_rational::mGetGCD(int x, int y) const {
    if (x == 0 || y == 0) return 1;
    while (x != y)
        if (x > y)
            x = x - y;
        else y = y - x;
    return x;
}

lib_rational lib_rational::operator+(lib_rational const &second) const {
    int denomLcm = (long) mDenominator * second.mDenominator / mGetGCD(mDenominator, second.mDenominator);
    int denominator = denomLcm;
    int numerator = mNumerator * (denomLcm / mDenominator) + second.mNumerator * (denomLcm / second.mDenominator);
    return {numerator, denominator};
}

lib_rational::lib_rational(int mNumerator, int mDenominator) : mNumerator(mNumerator), mDenominator(mDenominator) {
    mTypify();
    reduse();
}

lib_rational lib_rational::operator-(lib_rational const &second) const {
    int denomLcm = (long) mDenominator * second.mDenominator / mGetGCD(mDenominator, second.mDenominator);
    int denominator = denomLcm;
    int numerator = mNumerator * (denomLcm / mDenominator) - second.mNumerator * (denomLcm / second.mDenominator);
    return {numerator, denominator};
}

lib_rational lib_rational::operator*(lib_rational const &second) const {
    int num = mNumerator * second.mNumerator;
    int denom = mDenominator * second.mDenominator;
    return {num, denom};
}

lib_rational lib_rational::operator/(lib_rational const &second) const {
    int num = mNumerator * second.mDenominator;
    int denom = mDenominator * second.mNumerator;
    return {num, denom};
}

lib_rational::lib_rational(lib_rational const &arg) {
    mNumerator = arg.mNumerator;
    mDenominator = arg.mDenominator;
    mTypify();
    reduse();
}

ostream &operator<<(ostream &os, const lib_rational &rational) {
    os << rational.mNumerator * rational.mSign << "|" << rational.mDenominator;
    return os;
}

lib_rational::lib_rational() {
    mNumerator = 0;
    mDenominator = 1;
    mSign = 1;
}
