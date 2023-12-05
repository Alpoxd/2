#include "matrix1.h"

void error(const char* p);

matrix::matrix() : row(1) {
	mat = new dFraction*[row];
	mat[0] = new dFraction[1];
}
matrix::matrix(int c, int r) : row(r) {
	if (c <= 0 or r <= 0) error("1");
	mat = new dFraction*[row];
	for (int i = 0; i < row; i++) mat[i] = new dFraction[c];
	if (mat == nullptr) error("2");
}
matrix::matrix(int r) : matrix(1, r) {};

matrix::matrix(matrix& x) : matrix(x.row) {
	for (int i = 0; i < row; i++) {
		mat[i] = new dFraction[((vector)x[i]).size()];
		for (int j = 0; j < ((vector)x[i]).size(); j++) mat[i][j] = x.mat[i][j];
	}
}

matrix::matrix(std::vector<std::vector<float>> x) : matrix(x.size()) {
	for (int i = 0; i < row; i++) {
		mat[i] = new dFraction[x[i].size()];
		for (int j = 0; j < x[i].size(); j++) mat[i][j] = x[i][j];
	}
}
matrix::~matrix() {
	if (mat != nullptr) {
		for (int i = 0; i < row; i++) if (mat[i] != nullptr) delete[] mat[i];
		delete[] mat;
	}
}
dFraction* matrix::operator[](int i) {
	if (i < 0 || i > row - 1) error("3");
	return mat[i];
}
void matrix::operator = (matrix& x) {
	if (&x != this) {
		if (row != x.row) {
			if (mat != nullptr) delete[] mat;
			row = x.row;
			mat = new dFraction*[row];
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < ((vector)x.mat[i]).size(); j++) mat[i][j] = x.mat[i][j];
		}
	}
}
//void matrix::operator = (std::vector<std::vector<float>> x) {
//	for (int i = 0; i < (row < x.size() ? row : x.size()); i++) {
//		
//	}
//}
bool matrix::operator == (matrix& x) {
	if (x.row != row) return false;
	for (int i = 0; i < row; i++) {
		if (((vector)mat[i]).size() != ((vector)x.mat[i]).size()) return false;
		for (int j = 0; j < ((vector)mat[i]).size(); j++) if (mat[i][j] != x.mat[i][j]) return false;
	}
	return true;
}
bool matrix::operator != (matrix& x) {
	return !(x == *this);
}
void matrix::print() {
	printf("{\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < ((vector)mat[i]).size(); j++) mat[i][j].print();
		printf("\n");
	}
	printf("}\n");
}