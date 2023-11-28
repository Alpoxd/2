#include "matrix.h"

void error(const char* p);

matrix::matrix() : row(1) { mat = new vector[1]; }
matrix::matrix(int r) : row(r) { mat = new vector[row]; }
matrix::matrix(int c, int r) : row(r) { mat = new vector[row]{ c }; }
matrix::matrix(matrix& x) : matrix(x.row) {
	for (int i = 0; i < row; i++) mat[i] = x.mat[i];
}
matrix::matrix(std::vector<std::vector<float>> x) : matrix(x.size()) {
	for (int i = 0; i < x.size(); i++) {
		vector temp(x[i]);
		el(i) = temp;
	}
}
vector& matrix::operator[](int i) {
	if (i < 0 || i > row - 1) error("3");
	return mat[i];
}
matrix::~matrix() {
	if (mat != nullptr) delete[] mat;
}
void matrix::print() {
	printf("{\n");
	for (int i = 0; i < row; i++) mat[i].print();
	printf("}\n");
}
void matrix::push_back(vector x) {
	matrix temp(row + 1);
	for (int i = 0; i < row; i++) temp[i] = el(i);
	delete[] mat;
	row++;
	mat = new vector[row];
	for (int i = 0; i < row - 1; i++) el(i) = temp[i];
	el(row - 1) = x;
}