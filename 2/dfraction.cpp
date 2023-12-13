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
dFraction::dFraction(Fraction x, int fl) :Fraction(x) {
	checkflag();
	if (fl == 1) flag = fl;
};
dFraction dFraction::operator + (dFraction a) {
	return dFraction((Fraction)a + (Fraction)*this, flag || a.flag);
}
dFraction dFraction::operator - (dFraction a) {
	return dFraction((Fraction)*this - (Fraction)a, flag || a.flag);
}
dFraction dFraction::operator * (dFraction a) {
	return dFraction((Fraction)a * (Fraction)*this, flag || a.flag);
}
dFraction dFraction::operator / (dFraction a) {
	return dFraction((Fraction)*this / (Fraction)a, flag || a.flag);
}
bool dFraction::operator == (dFraction a) {
	return (numerator == a.numerator && denominator == a.denominator && flag == a.flag) ? true : false;
}
bool dFraction::operator != (dFraction a) {
	return (numerator != a.numerator || denominator != a.denominator || flag != a.flag) ? true : false;
}