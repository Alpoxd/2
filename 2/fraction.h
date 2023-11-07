#pragma once
class Fraction {
protected:
    int numerator, denominator;
public:
    Fraction();
    Fraction(float);
    Fraction(int, int);
    void print();
    Fraction operator + (Fraction);
    Fraction operator - (Fraction);
    Fraction operator * (Fraction);
    Fraction operator / (Fraction);
    bool operator == (Fraction);
private:
    int nodo(int, int);
};