#include <iostream>
#include <cmath>
#include "dfraction.h"

void dFraction::print(void) {
	if (flag == 1) printf("* ");
	Fraction::print();
}
void dFraction::checkflag() {
	if (abs(numerator / denominator) >= 10000) {
		if (numerator < 0) numerator = -10000;
		else numerator = 10000;
		denominator = 1;
		flag = 1;
	}
	else flag = 0;
}
dFraction::dFraction() :Fraction() { flag = 0; }
dFraction::dFraction(float value):Fraction(value) { checkflag(); }
dFraction::dFraction(Fraction x):Fraction(x) { checkflag(); }
dFraction::dFraction(int num, int den, int fl) :Fraction(num, den) {
	checkflag();
	if (fl == 1) flag = fl;
};
dFraction dFraction::operator + (dFraction a) {
	if (denominator == a.denominator) {
		if (flag == 1 || a.flag == 1) return dFraction(numerator + a.numerator, denominator, 1);
		else return dFraction(numerator + a.numerator, denominator, 0);
	}
	else {
		if (flag == 1 || a.flag == 1) return dFraction(numerator * a.denominator + a.numerator * denominator, denominator * a.denominator, 1);
		else return dFraction(numerator * a.denominator + a.numerator * denominator, denominator * a.denominator, 0);
	}
}
dFraction dFraction::operator - (dFraction a) {
	if (denominator == a.denominator) {
		if (flag == 1 || a.flag == 1) return dFraction(numerator - a.numerator, denominator, 1);
		else return dFraction(numerator - a.numerator, denominator, 0);
	}
	else {
		if (flag == 1 || a.flag == 1) return dFraction(numerator * a.denominator - a.numerator * denominator, denominator * a.denominator, 1);
		else return dFraction(numerator * a.denominator - a.numerator * denominator, denominator * a.denominator, 0);
	}
}
dFraction dFraction::operator * (dFraction a) {
	if (flag == 1 || a.flag == 1) return dFraction(a.numerator * numerator, a.denominator * denominator, 1);
	else return dFraction(a.numerator * numerator, a.denominator * denominator, 0);
}
dFraction dFraction::operator / (dFraction a) {
	if (flag == 1 || a.flag == 1) return dFraction(numerator * a.denominator, denominator * a.numerator, 1);
	else return dFraction(numerator * a.denominator, denominator * a.numerator, 0);
}