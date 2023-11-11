#include "dvector.h"

dvector::dvector() {
	dvec = nullptr;
	len = 0;
}
dvector::dvector(int s) {
	if (s <= 0) error("1");
	dvec = new vector[s];
	if (dvec == 0) error("2");
	len = s;
}
dvector::dvector(std::vector<std::vector<float>> x) : dvector(x.size()){
	for (int i = 0; i < len; i++) {
		vector temp(x[i]);
		mas(i) = temp;
	}
}
dvector::~dvector() {
	if (dvec != nullptr) delete[] dvec;
}
vector& dvector::operator[](int i) {
	if (i < 0 || i > len - 1) error("3");
	return dvec[i];
}
void dvector::push_back(vector x) {
	dvector temp(len + 1);
	for (int i = 0; i < len; i++) temp[i] = mas(i);
	delete[] vec;
	len++;
	dvec = new vector[len];
	for (int i = 0; i < len - 1; i++) mas(i) = temp[i];
	mas(len - 1) = x;
}
void dvector::print() {
	printf("{\n");
	for (int i = 0; i < size(); i++) {
		mas(i).print();
	}
	printf("}\n");
}