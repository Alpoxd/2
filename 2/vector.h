#pragma once
#include "dfraction.h"
#include <vector>
class vector {
protected:
	dFraction* vec;
	int len;
public:
	vector();
	vector(int);
	vector(std::vector<float>);
	vector(vector&);
	vector(vector&&) noexcept;
	~vector();
	inline int size() { return len; }
	void setLen(int);
	inline dFraction& el(int i) { return vec[i]; }
	dFraction& operator [] (int);
	void operator = (vector&);
	bool operator == (vector&);
	vector operator + (vector&);
	vector operator += (vector&);
	vector operator - (vector&);
	void push_back(dFraction);
	void print();
};