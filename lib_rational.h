
#ifndef TASK4_LIB_RATIONAL_H
#define TASK4_LIB_RATIONAL_H


class lib_rational {
public:
    void reduse();
    lib_rational operator+(lib_rational const &) const;
    lib_rational operator-(lib_rational const &) const;
    lib_rational operator*(lib_rational const &) const;

    lib_rational(int , int );

private:
    int mNumerator;
    int mDenominator;
    int mSign;
    int mGetGCD(int, int) const ;
    void mTypify();


};


#endif //TASK4_LIB_RATIONAL_H
