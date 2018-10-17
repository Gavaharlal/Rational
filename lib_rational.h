
#ifndef TASK4_LIB_RATIONAL_H
#define TASK4_LIB_RATIONAL_H

#include <iostream>
using std::ostream;

class lib_rational {
public:

    void reduse();

    lib_rational operator+(lib_rational const &) const;

    lib_rational operator-(lib_rational const &) const;

    lib_rational operator*(lib_rational const &) const;

    lib_rational operator/(lib_rational const &) const;

    lib_rational(int, int);

    lib_rational();

    lib_rational(lib_rational const &);

    bool operator<(const lib_rational &rhs) const;

    bool operator>(const lib_rational &rhs) const;

    bool operator<=(const lib_rational &rhs) const;

    bool operator>=(const lib_rational &rhs) const;

    friend ostream& operator<<(ostream& os, const lib_rational&);


private:
    int mNumerator;
    int mDenominator;
    int mSign;


    int mGetGCD(int, int) const;

    void mTypify();


};


#endif //TASK4_LIB_RATIONAL_H
