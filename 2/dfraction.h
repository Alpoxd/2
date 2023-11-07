#pragma once
#include "fraction.h"
class dFraction : public Fraction {
protected:
    int flag;
public:
    dFraction();
    dFraction(float);
    dFraction(Fraction);
    void print();
    void checkflag();
};