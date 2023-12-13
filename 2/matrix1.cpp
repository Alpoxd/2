#include "matrix1.h"

void error(const char* p);

matrix::matrix() {
	mat = new dFraction*[row];
	if (mat == nullptr or mat == 0) error("2");
	else {
		row = 1;
		mat[0] = new dFraction[1];
	}
}

matrix::matrix(int c, int r) {
	if (c <= 0 or r <= 0) error("1");
	mat = new dFraction*[r];
	row = r;
	if (mat == nullptr or mat == 0) error("2");
	for (int i = 0; i < row; i++) {
		delete[] mat[i];
		mat[i] = new dFraction[c];
	}
}

matrix::matrix(matrix& x) : matrix(1, x.row) {
	for (int i = 0; i < row; i++) {
		delete[] mat[i];
		mat[i] = new dFraction[((vector)x[i]).size()];
		mat[i] = x.mat[i];
	}
}

matrix::matrix(std::vector<std::vector<float>> x) : matrix(1, x.size()) {
	for (int i = 0; i < row; i++) {
		delete[] mat[i];
		mat[i] = new dFraction[x[i].size()];
		for (int j = 0; j < x[i].size(); j++) mat[i][j] = x[i][j];
	}
}
matrix::~matrix() {
	if (mat != nullptr) {
		for (int i = 0; i < row; i++) {
			if (mat[i] != nullptr) {
				delete[] mat[i];
				mat[i] = nullptr;
			}
		}
		delete[] mat;
		mat = nullptr;
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
			delete[] mat[i];
			mat[i] = new dFraction[((vector)x[i]).size()];
			mat[i] = x.mat[i];
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
		if (((vector)mat[i]).size() != ((vector)x.mat[i]).size() or mat[i] != x.mat[i]) return false;
	}
	return true;
}
bool matrix::operator != (matrix& x) {
	return !(x == *this);
}
void matrix::print() {
	printf("{\n");
	for (int i = 0; i < row; i++) {
		((vector)mat[i]).print();
		printf("\n");
	}
	printf("}\n");
}