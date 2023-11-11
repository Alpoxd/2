#pragma once
#include "vector.h"
class dvector : public vector {
protected:
	vector* dvec;
	int len;
public:
	dvector();
	dvector(int);
	dvector(std::vector<std::vector<float>>);
	~dvector();
	inline int size() { return len; }
	inline vector& mas(int i) { return dvec[i]; }
	vector& operator [] (int);
	void push_back(vector);
	void print();
};