#pragma once
#include<iostream>



class Vector
{
	int size;
	double* data;

public:
	Vector();
	Vector(int s);
	Vector(const Vector& v);
	~Vector();
	int getSize();
	double& operator[](int pos);
	Vector& operator++();
	Vector operator++(int);
	Vector& operator--();
	Vector operator--(int);
	friend std::ostream& operator<<(std::ostream &out, const Vector &v);

};

