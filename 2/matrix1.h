#pragma once
#include "dFraction.h"
#include <vector>
class matrix {
protected:
	dFraction** mat;
	int col;
	int row;
public:
	matrix();
	matrix(int, int);
	matrix(int);
	matrix(matrix&);
	matrix(std::vector<std::vector<float>>);
	~matrix();
	dFraction* operator [] (int);
	void operator = (matrix&);
	void operator = (std::vector<std::vector<float>>);
	bool operator == (matrix&);
	bool operator != (matrix&);
	void print();
};