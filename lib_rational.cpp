

#include "lib_rational.h"
#include <cmath>

void lib_rational::reduce() {
    int gcd = mGetGCD(mNumerator, mDenominator);
    mNumerator /= gcd;
    mDenominator /= gcd;
}

void lib_rational::mTypify() {
    if (mNumerator * (long) mDenominator >= 0) return;
    else {
        mSign = -1;
        mDenominator = abs(mDenominator);
        mNumerator = abs(mNumerator);
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
    int numerator = mSign * mNumerator * (denomLcm / mDenominator) +
                    second.mSign * second.mNumerator * (denomLcm / second.mDenominator);
    return {numerator, denominator};
}

lib_rational::lib_rational(int mNumerator, int mDenominator) : mNumerator(mNumerator), mDenominator(mDenominator) {
    mTypify();
    reduce();
}

lib_rational lib_rational::operator-(lib_rational const &second) const {
    int denomLcm = (long) mDenominator * second.mDenominator / mGetGCD(mDenominator, second.mDenominator);
    int denominator = denomLcm;
    int numerator = mSign * mNumerator * (denomLcm / mDenominator) -
                    second.mSign * second.mNumerator * (denomLcm / second.mDenominator);
    return {numerator, denominator};
}

lib_rational lib_rational::operator*(lib_rational const &second) const {
    lib_rational res = *this;
    res *= second;
    return res;
}

lib_rational lib_rational::operator/(lib_rational const &second) const {
    int num = mSign * second.mSign * mNumerator * second.mDenominator;
    int denom = mDenominator * second.mNumerator;
    return {num, denom};
}

lib_rational::lib_rational(lib_rational const &arg) {
    mNumerator = arg.mNumerator;
    mDenominator = arg.mDenominator;
    mSign = arg.mSign;
    mTypify();
    reduce();
}

ostream &operator<<(ostream &os, const lib_rational &rational) {
    os << rational.mNumerator * rational.mSign << "|" << rational.mDenominator;
    return os;
}

bool lib_rational::operator<(const lib_rational &second) const {
    int denomLcm = (long) mDenominator * second.mDenominator / mGetGCD(mDenominator, second.mDenominator);
    int diff = mSign * mNumerator * (denomLcm / mDenominator) -
               second.mSign * second.mNumerator * (denomLcm / second.mDenominator);
    return diff < 0;
}

bool lib_rational::operator>(const lib_rational &rhs) const {
    return rhs < *this;
}

bool lib_rational::operator<=(const lib_rational &rhs) const {
    return !(rhs < *this);
}

bool lib_rational::operator>=(const lib_rational &rhs) const {
    return !(*this < rhs);
}

lib_rational &lib_rational::operator*=(lib_rational const &second) {
    mNumerator *= second.mNumerator;
    mDenominator *= second.mDenominator;
    mSign *= second.mSign;
    mTypify();
    reduce();
    return *this;
}

lib_rational &lib_rational::pow(int n) {
    if (n == 0) {
        mNumerator = 1;
        mDenominator = 1;
        mSign = 1;
    } else {
        int num = mNumerator;
        int denom = mDenominator;
        for (int i = 0; i < n - 1; ++i) {
            mNumerator *= num;
            mDenominator *= denom;
            reduce();
        }
        mSign = (n % 2) ? mSign : 1;
    }
    return *this;
}

bool lib_rational::operator==(const lib_rational &rhs) const {
    return mNumerator == rhs.mNumerator &&
           mDenominator == rhs.mDenominator &&
           mSign == rhs.mSign;
}

bool lib_rational::operator!=(const lib_rational &rhs) const {
    return !(rhs == *this);
}

lib_rational::lib_rational() = default;
