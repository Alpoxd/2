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
    dFraction(int, int, int);
    dFraction operator + (dFraction);
    dFraction operator - (dFraction);
    dFraction operator * (dFraction);
    dFraction operator / (dFraction);
private:
    void checkflag();
};