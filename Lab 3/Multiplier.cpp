#include "Multiplier.h"
#include<iostream>
#include<fstream>

Multiplier::Multiplier()
{
	operandCount = 20;
	values = new double[operandCount];
	for (int k = 0; k < operandCount; ++k)
		values[k] = 0;
}

Multiplier::Multiplier(int n)
{
	operandCount = n;
	values = new double[operandCount];
	for (int k = 0; k < operandCount; ++k)
		values[k] = 0;
}

double Multiplier::calculate()
{
	double res = 1;
	for (int k = 0; k < operandCount; ++k)
		res *= values[k];

	return res;
}

void Multiplier::logToScreen()
{
	std::cout << operandCount << " operands:\n";
	char temp = '*';
	for (int k = 0; k < operandCount; ++k) {
		if (k == operandCount - 1) temp = ' ';
		if (values[k] < 0)
			std::cout << '(' << values[k] << ')' << temp;
		else std::cout << values[k] << temp;
	}
	std::cout << "\n->" << calculate() << "\n\n";
}

void Multiplier::logToFile(const std::string & fileName)
{
	std::ofstream file;
	file.open(fileName);
	char temp = '*';
	file << operandCount << " operands:\n";
	for (int k = 0; k < operandCount; ++k) {
		if (k == operandCount - 1) temp = ' ';
		if (values[k] < 0)
			file << '(' << values[k] << ')' << temp;
		else file << values[k] << temp;
	}
	file << "\n->" << calculate() << "\n\n";
}
