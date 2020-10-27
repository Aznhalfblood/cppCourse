#pragma once
#include<assert.h>


template <class T>
class Vector
{
	int size;
	T* data;

public:
	Vector() {
		size = 0;
		data = NULL;
	}

	Vector(int s) {
		size = s;
		data = new T[s];
	}

	Vector(const Vector& v) {
		size = v.size;
		data = new T[size];
		for (int k = 0; k < size; k++)
			data[k] = v.data[k];
	}

	~Vector() {
		delete[] data;
	}

	int getSize() { return size; }

	T& operator[](int pos) {
		assert(!(pos > size || pos < 0));
		return data[pos];
	}

	Vector& operator++() {
		for (int k = 0; k < size; k++)
			++data[k];

		return *this;
	}

	Vector operator++(int) {
		Vector V(*this);
		++*this;
		return V;
	}

	Vector& operator--() {
		for (int k = 0; k < size; k++)
			--data[k];

		return *this;
	}

	Vector operator--(int) {
		Vector V(*this);
		--*this;
		return V;
	}

};

