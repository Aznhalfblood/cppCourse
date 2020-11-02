#pragma once
#include"Vector.h"



class Matrix
{
	int rows;
	int cols;
	double** data;


public:

	Matrix();
	Matrix(unsigned r, unsigned c);
	Matrix(const Matrix& m);
	~Matrix();
	int getR();
	int getC();
	void Init();
	Vector conv();
	double& at(int i, int j)const;
	void setAt(int i, int j, double val);
	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);
	friend std::ostream& operator<<(std::ostream &out, const Matrix &m);


};

