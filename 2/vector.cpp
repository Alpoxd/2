#include <iostream>
#include "vector.h"

void error(const char* p) {
	printf("\nError code: %s", p);
	exit(EXIT_FAILURE);
}
void vector::print() {
	for (int i = 0; i < size(); i++) {
		el(i).print();
	}
}
vector::vector(int s) {
	if (s <= 0) error("1");
	vec = new dFraction[s];
	if (vec == 0) error("2");
	len = s;
}
vector::vector(vector& x) :vector(x.len) {
	for (int i = 0; i < size(); i++) el(i) = x.el(i);
}
vector::vector(vector&& x) {
	vec = x.vec;
	len = x.len;
	x.vec = nullptr;
	x.len = 0;
}
vector::~vector() {
	delete[] vec;
}
dFraction& vector::operator[](int i) {
	if (i < 0 || i > len - 1) error("3");
	return vec[i];
}
vector vector::operator + (vector& x) {
	if (len != x.len) error("+: different size");
	vector res(len);
	for (int i = 0; i < len; i++) res.el(i) = el(i) + x.el(i);
	return res;
}
vector vector::operator += (vector& x) {
	vector res(len + x.len);
	for (int i = 0; i < len; i++) res[i] = el(i);
	for (int i = len; i < len + x.len; i++) res[i] = el(i - len);
	return res;
}
vector vector::operator - (vector& x) {
	if (len != x.len) error("-: different size");
	vector res(len);
	for (int i = 0; i < len; i++) res.el(i) = el(i) - x.el(i);
	return res;
}
void vector::operator = (vector& x) {
	if (this != &x) {
		delete[] vec;
		len = x.len;
		for (int i = 0; i < len; i++) el(i) = x.el(i);
	}
}
bool vector::operator == (vector& x) {
	if (len != x.len) return false;
	for (int i = 0; i < len; i++) {
		if (el(i) == x.el(i)) return false;
	}
	return true;
}