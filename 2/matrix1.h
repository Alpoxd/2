#pragma once
#include "vector.h"
#include <vector>
class matrix {
protected:
	dFraction** mat;
	int row;
public:
	matrix();
	matrix(int, int);
	matrix(int);
	matrix(matrix&);
	matrix(std::vector<std::vector<float>>);
	~matrix();
	inline int size() { return row; }
	dFraction* operator [] (int);
	void operator = (matrix&);
	bool operator == (matrix&);
	bool operator != (matrix&);
	void print();
};