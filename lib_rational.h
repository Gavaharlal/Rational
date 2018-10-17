
#ifndef TASK4_LIB_RATIONAL_H
#define TASK4_LIB_RATIONAL_H

#include <iostream>

using std::ostream;

class lib_rational {
public:

    void reduce();

    lib_rational operator+(lib_rational const &) const;

    lib_rational operator-(lib_rational const &) const;

    lib_rational operator*(lib_rational const &) const;

    lib_rational &operator*=(lib_rational const &);

    lib_rational operator/(lib_rational const &) const;

    lib_rational &pow(int);

    lib_rational(int, int);

    lib_rational(lib_rational const &);

    bool operator<(const lib_rational &rhs) const;

    bool operator>(const lib_rational &rhs) const;

    bool operator==(const lib_rational &rhs) const;

    bool operator!=(const lib_rational &rhs) const;

    bool operator<=(const lib_rational &rhs) const;

    bool operator>=(const lib_rational &rhs) const;

    friend ostream& operator<<(ostream& os, const lib_rational&);


private:
public:
    lib_rational();

private:
    int mNumerator = 0;
    int mDenominator = 1;
    int mSign = 1;


    int mGetGCD(int, int) const;

    void mTypify();


};


#endif //TASK4_LIB_RATIONAL_H
