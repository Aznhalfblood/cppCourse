#include"Vector.h"
#include<assert.h>

Vector::Vector() {
	size = 0;
	data = NULL;
}

Vector::Vector(int s) {
	size = s;
	data = new double[s];
}

Vector::Vector(const Vector& v) {
	size = v.size;
	data = new double[size];
	for (int k = 0; k < size; k++)
		data[k] = v.data[k];
}

Vector::~Vector() {
	delete[] data;
}

int Vector::getSize() {
	return size;
}

double& Vector::operator[](int pos) {
	assert(!(pos > size || pos < 0));
	return data[pos];
}

Vector& Vector::operator++() {
	for (int k = 0; k < size; k++)
		++data[k];

	return *this;
}

Vector Vector::operator++(int) {
	Vector V(*this);
	++*this;
	return V;
}

Vector& Vector::operator--() {
	for (int k = 0; k < size; k++)
		--data[k];

	return *this;
}

Vector Vector::operator--(int) {
	Vector V(*this);
	--*this;
	return V;
}

std::ostream & operator<<(std::ostream & out, const Vector & v)
{
	for (int k = 0; k < v.size; ++k)
		out << v.data[k] << ' ';
	out << '\n';

	return out;
}
