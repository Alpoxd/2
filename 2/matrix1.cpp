#include "matrix1.h"

void error(const char* p);

matrix::matrix() : col(1), row(1) {
	mat = new dFraction*[row];
	mat[0] = new dFraction[col];
}
matrix::matrix(int c, int r) : col(c), row(r) {
	if (c <= 0 or r <= 0) error("1");
	mat = new dFraction*[row];
	for (int i = 0; i < row; i++) mat[i] = new dFraction[col];
	if (mat == nullptr) error("2");
}
matrix::matrix(int r) : matrix(1, r) {};

matrix::matrix(matrix& x) : matrix(x.col, x.row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mat[i][j] = x[i][j];
		}
	}
}

matrix::matrix(std::vector<std::vector<float>> x) : matrix(x[0].size(), x.size()) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) mat[i][j] = x[i][j];
	}
}
matrix::~matrix() {
	if (mat != nullptr) delete[] mat;
}
dFraction* matrix::operator[](int i) {
	if (i < 0 || i > row - 1) error("3");
	return mat[i];
}
void matrix::operator = (matrix& x) {
	if (&x != this) {
		if (row != x.row or col != x.col) {
			if (mat != nullptr) delete[] mat;
			row = x.row;
			col = x.col;
			mat = new dFraction*[row];
			for (int i = 0; i < row; i++) mat[i] = new dFraction[col];
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				mat[i][j] = x.mat[i][j];
			}
		}
	}
}
void matrix::operator = (std::vector<std::vector<float>> x) {
	for (int i = 0; i < (row < x.size() ? row : x.size()); i++) {
		for (int j = 0; j < (col < x[i].size() ? col : x[i].size()); j++) mat[i][j] = x[i][j];
	}
}
bool matrix::operator == (matrix& x) {
	if (x.col != col) return false;
	if (x.row != row) return false;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) if (mat[i][j] != x[i][j]) return false;
	}
	return true;
}
bool matrix::operator != (matrix& x) {
	return !(x == *this);
}
void matrix::print() {
	printf("{\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) mat[i][j].print();
		printf("\n");
	}
	printf("}\n");
}