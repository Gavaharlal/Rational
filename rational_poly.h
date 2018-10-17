
#ifndef TASK4_RATIONAL_POLY_H
#define TASK4_RATIONAL_POLY_H


#include "lib_rational.h"
#include <vector>

using std::vector;

class rational_poly {
public:
    explicit rational_poly(vector<lib_rational> const &);

    void addFactor(lib_rational const &);

    lib_rational eval(lib_rational const &);

    void calculateLargest(lib_rational const&, lib_rational const&);

    rational_poly();


private:
    vector<lib_rational> mPolynomial;
};


#endif //TASK4_RATIONAL_POLY_H
