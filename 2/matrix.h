#pragma once
#include "vector.h"
class matrix {
private:
	vector* mat;
	int row;
public:
	matrix();
	matrix(int);
	matrix(int, int);
	matrix(matrix&);
	matrix(std::vector<std::vector<float>>);
	~matrix();
	inline int size() { return row; }
	inline vector& el(int i) { return mat[i]; }
	vector& operator [] (int);
	void operator = (matrix&); 
	void push_back(vector);
	void print();
};