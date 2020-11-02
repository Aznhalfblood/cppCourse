#include"Matrix.h"
#include<assert.h>
#include<math.h>

Matrix::Matrix() {
	rows = cols = 0;
	data = NULL;
}

Matrix::Matrix(unsigned r, unsigned c) {
	rows = r;
	cols = c;
	data = new double*[r];
	for (int k = 0; k < r; k++)
		data[k] = new double[c];
}

Matrix::Matrix(const Matrix& m) {
	rows = m.rows;
	cols = m.cols;
	data = new double*[rows];
	for (int k = 0; k < rows; k++)
		data[k] = new double[cols];

	for (int k = 0; k < rows; k++)
		for (int l = 0; l < cols; l++)
			data[k][l] = m.data[k][l];
}

Matrix::~Matrix() {
	for (int k = 0; k < rows; k++)
		delete[]data[k];

	delete[]data;
}

int Matrix::getR() { return rows; }
int Matrix::getC() { return cols; }

void Matrix::Init()
{
	for (int k = 0; k < rows; ++k)
		for (int l = 0; l < cols; ++l)
			data[k][l] = sin(k - l) + cos(k + l);
}

Vector Matrix::conv()
{
	int r = rows;
	int c = cols;
	Vector V(r*c);

	for (int l = 0; l < r; l++)
		for (int k = 0; k < c; k++)
			V[k + l * c] = data[r - l - 1][k];

	return V;
}

double& Matrix::at(int i, int j)const {
	assert(i >= 0 && i < rows && j >= 0 && j < cols);
	return data[i][j];
}

void Matrix::setAt(int i, int j, double val) {
	assert(i >= 0 && i < rows && j >= 0 && j < cols);
	data[i][j] = val;
}

Matrix& Matrix:: operator++() {
	for (int k = 0; k < rows; k++)
		for (int l = 0; l < cols; l++)
			++data[k][l];

	return *this;
}

Matrix Matrix::operator++(int) {
	Matrix M(*this);
	++*this;
	return M;
}

Matrix& Matrix::operator--() {
	for (int k = 0; k < rows; k++)
		for (int l = 0; l < cols; l++)
			--data[k][l];

	return *this;
}

Matrix Matrix::operator--(int) {
	Matrix M(*this);
	--*this;
	return M;
}

std::ostream & operator<<(std::ostream & out, const Matrix & m)
{
	for (int k = 0; k < m.rows; ++k) {
		for (int l = 0; l < m.cols; ++l)
			out << m.data[k][l] << ' ';
		out << '\n';
	}

	return out;
}
