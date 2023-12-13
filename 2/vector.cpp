#include <iostream>
#include "vector.h"

void error(const char* p) {
	printf("\nError code: %s", p);
	exit(EXIT_FAILURE);
}
void vector::print() {
	printf("{");
	for (int i = 0; i < size(); i++) el(i).print();
	printf("}\n");
}
vector::vector() : len(1) {
	vec = new dFraction[1];
}
vector::vector(int s) {
	if (s <= 0) error("1");
	vec = new dFraction[s];
	if (vec == 0) error("2");
	len = s;
}
vector::vector(std::vector<float> x) :vector(x.size()){
	for (int i = 0; i < len; i++) el(i) = x[i];
}
vector::vector(dFraction* x) {
	vec = x;
	len = sizeof(x) / sizeof(dFraction);
}
vector::vector(vector& x) :vector(x.len) {
	for (int i = 0; i < size(); i++) el(i) = x[i];
}
vector::vector(vector&& x) noexcept {
	vec = x.vec;
	len = x.len;
	x.vec = nullptr;
	x.len = 0;
}
vector::~vector() {
	if (vec != nullptr) {
		delete[] vec;
		vec = nullptr;
	}
}
dFraction& vector::operator[](int i) const {
	if (i < 0 || i > len - 1) error("3");
	return vec[i];
}
vector vector::operator + (const vector& x) {
	if (len != x.len) error("+: different size");
	for (int i = 0; i < len; i++) el(i) = el(i) + x[i];
	return *this;
}
vector vector::operator += (const vector& x) {
	vector res(len + x.len);
	for (int i = 0; i < len; i++) res[i] = el(i);
	for (int i = len; i < len + x.len; i++) res[i] = el(i - len);
	return res;
}
vector vector::operator - (const vector& x) {
	if (len != x.len) error("-: different size");
	for (int i = 0; i < len; i++) el(i) = el(i) - x[i];
	return *this;
}
void vector::operator = (const vector& x) {
	if (vec != x.vec) {
		if (len != x.len) {
			if (vec != nullptr) delete[] vec;
			vec = new dFraction[x.len];
			len = x.len;
		}
		for (int i = 0; i < len; i++) el(i) = x[i];
	}
}
bool vector::operator == (const vector& x) {
	if (len != x.len) return false;
	for (int i = 0; i < len; i++) {
		if (el(i) != x[i]) return false;
	}
	return true;
}
void vector::push_back(dFraction x) {
	vector temp(len + 1);
	for (int i = 0; i < len; i++) temp[i] = el(i);
	delete[] vec;
	len++;
	vec = new dFraction[len];
	for (int i = 0; i < len - 1; i++) el(i) = temp[i];
	el(len - 1) = x;
}
void vector::setLen(int s)
{
	len = s;
	vec = new dFraction[len];
	for (int x = 0; x < len; x++) vec[x] = dFraction();
}