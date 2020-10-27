#pragma once
#include<assert.h>

template <class T>
class Matrix
{
	int rows;
	int cols;
	T** data;


public:

	Matrix() {
		rows = cols = 0;
		data = NULL;
	}

	Matrix(unsigned r, unsigned c) {
		rows = r;
		cols = c;
		data = new T*[r];
		for (int k = 0; k < r; k++)
			data[k] = new T[c];
	}

	Matrix(const Matrix& m) {
		rows = m.rows;
		cols = m.cols;
		data = new T*[rows];
		for (int k = 0; k < rows; k++)
			data[k] = new T[cols];

		for (int k = 0; k < rows; k++)
			for (int l = 0; l < cols; l++)
				data[k][l] = m.data[k][l];
	}
	
	~Matrix() {
		for (int k = 0; k < rows; k++)
			delete[]data[k];

		delete[]data;
	}

	int getR() { return rows; }
	int getC() { return cols; }


	T& at(int i, int j)const {
		assert(i >= 0 && i < rows && j >= 0 && j < cols);
		return data[i][j];
	}

	void setAt(int i, int j, T val) {
		assert(i >= 0 && i < rows && j >= 0 && j < cols);
		data[i][j] = val;
	}

	Matrix& operator++() {
		for (int k = 0; k < rows; k++)
			for (int l = 0; l < cols; l++)
				++data[k][l];

		return *this;
	}

	Matrix operator++(int) {
		Matrix M(*this);
		++*this;
		return M;
	}

	Matrix& operator--() {
		for (int k = 0; k < rows; k++)
			for (int l = 0; l < cols; l++)
				--data[k][l];

		return *this;
	}

	Matrix operator--(int) {
		Matrix M(*this);
		--*this;
		return M;
	}


};

