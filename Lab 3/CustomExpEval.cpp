#include "CustomExpEval.h"
#include<iostream>
#include<fstream>


int compare(const void *i, const void *j){
	return *(int*)i - *(int*)j;
}

CustomExpEval::CustomExpEval()
{
	operandCount = 20;
	values = new double[operandCount];
	for (int k = 0; k < operandCount; ++k)
		values[k] = 0;
}

CustomExpEval::CustomExpEval(int n)
{
	operandCount = n;
	values = new double[operandCount];
	for (int k = 0; k < operandCount; ++k)
		values[k] = 0;
}

double CustomExpEval::calculate() {

	double res = 0;
	for (int k = 0; k < operandCount; ++k)
		res += (k + 1)*values[k];

	return res;
}

void CustomExpEval::shufle() {
	qsort(values, operandCount, sizeof(double), compare);
}

void CustomExpEval::shufle(size_t i, size_t j){
	qsort(values + i, j, sizeof(double), compare);
}

void CustomExpEval::logToScreen()
{
	std::string temp = " + ";
	std::cout << operandCount << " operands:\n";
	for (int k = 0; k < operandCount; ++k) {
		if (k == operandCount - 1) temp = ' ';
		if (k == 0) {
			std::cout << values[k] << temp;
		}
		else {
			if (values[k] < 0)
				std::cout << k + 1 << "*(" << values[k] << ')' << temp;
			else std::cout << k + 1 << '*' << values[k] << temp;
		}
	}
	std::cout << "\n->" << calculate() << "\n\n";
}

void CustomExpEval::logToFile(const std::string & fileName)
{
	std::ofstream file;
	file.open(fileName);
	std::string temp = " + ";
	file << operandCount << " operands:\n";
	for (int k = 0; k < operandCount; ++k) {
		if (k == operandCount - 1) temp = ' ';
		if (k == 0) {
			file << values[k] << temp;
		}
		else {
			if (values[k] < 0)
				file << k + 1 << "*(" << values[k] << ')' << temp;
			else file << k + 1 << '*' << values[k] << temp;
		}
	}
	file << "\n->" << calculate() << "\n\n";
}
