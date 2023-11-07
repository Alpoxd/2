#include <iostream>
#include <cmath>
#include "dfraction.h"

void dFraction::print(void) {
	Fraction::print();
	if (flag == 1) printf("*\n");
	else printf("\n");
}
void dFraction::checkflag() {
	if (abs(numerator / denominator) >= 10000) flag = 1;
	else flag = 0;
}
dFraction::dFraction() :Fraction() { flag = 0; }

dFraction::dFraction(float value):Fraction(value) { checkflag(); }

dFraction::dFraction(Fraction x):Fraction(x) { checkflag(); }