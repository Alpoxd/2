#pragma once
#include "dfraction.h"
#include <vector>
class vector {
protected:
	dFraction* vec;
	int len;
public:
	vector(int);
	vector(std::vector<float>);
	vector(vector&);
	vector(vector&&);
	~vector();
	inline int size() { return len; }
	inline dFraction& el(int i) { return vec[i]; }
	dFraction& operator [] (int);
	void operator = (vector&);
	bool operator == (vector&);
	vector operator + (vector&);
	vector operator += (vector&);
	vector operator - (vector&);
	void print();
};