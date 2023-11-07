#include <stdio.h>
#include <cmath>
#include "fraction.h" 

void Fraction::print(void) {
	float res = numerator;
	res /= denominator;
	printf("%d / %d [%0.3f]\n", numerator, denominator, res);
}
Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
}
Fraction::Fraction(float value) {
	int cst = 10000;
	int intValue = (value * cst);
	if (intValue % cst != 0) {
		int nod = nodo(intValue, cst);
		numerator = intValue / nod;
		denominator = cst / nod;
	}
	else {
		numerator = intValue / cst;
		denominator = 1;
	}
}
Fraction::Fraction(int num, int den) {
	int nod = nodo(num, den);
	numerator = num / nod;
	denominator = den / nod;
}
int Fraction::nodo(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return nodo(a % b, b);
	return nodo(a, b % a);
}
Fraction Fraction::operator + (Fraction a) {
	if (denominator == a.denominator) {
		return Fraction(numerator + a.numerator, denominator);
	}
	else return Fraction(numerator * a.denominator + a.numerator * denominator, denominator * a.denominator);
}
Fraction Fraction::operator - (Fraction a) {
	if (a.denominator == denominator) {
		return Fraction(numerator - a.numerator, denominator);
	}
	else return Fraction(numerator * a.denominator - a.numerator * denominator, denominator * a.denominator);
}
Fraction Fraction::operator * (Fraction a) {
	return Fraction(a.numerator * numerator, a.denominator * denominator);
}
Fraction Fraction::operator / (Fraction a) {
	return Fraction(numerator * a.denominator, denominator * a.numerator);
}
bool Fraction::operator == (Fraction a) {
	return (numerator == a.numerator && denominator == a.denominator) ? true: false;
}