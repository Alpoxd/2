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
	matrix(matrix&);
	matrix(std::vector<std::vector<float>>);
	~matrix();
	inline int size() { return row; }
	//inline int len(int i) { return ((vector)(*this)[i]).size(); }
	//inline dFraction* relocate(dFraction* x, int y) { delete[] x; return new dFraction[y]; }
	dFraction* operator [] (int);
	void operator = (matrix&);
	bool operator == (matrix&);
	bool operator != (matrix&);
	void print();
};