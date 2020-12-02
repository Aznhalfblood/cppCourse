#include "Summator.h"
#include<iostream>
#include<fstream>



Summator::Summator()
{
	operandCount = 20;
	values = new double[operandCount];
	for (int k = 0; k < operandCount; ++k)
		values[k] = 0;
}

Summator::Summator(int n)
{
	operandCount = n;
	values = new double[operandCount];
	for (int k = 0; k < operandCount; ++k)
		values[k] = 0;
}

double Summator::calculate()
{
	double res = 0;
	for (int k = 0; k < operandCount; ++k)
		res += values[k];

	return res;
}

void Summator::logToScreen()
{
	std::cout << operandCount << " operands:\n";
	std::string temp = " + ";
	for (int k = 0; k < operandCount; ++k) {
		if (k == operandCount - 1) temp = ' ';
		if (values[k] < 0)
			std::cout << '(' << values[k] << ')' << temp;
		else std::cout << values[k] << temp;
	}
	std::cout << "\n->" << calculate() << "\n\n";

}

void Summator::logToFile(const std::string & fileName)
{
	std::ofstream file;
	file.open(fileName);
	std::string temp = " + ";
	file << operandCount << " operands:\n";
	for (int k = 0; k < operandCount; ++k) {
		if (k == operandCount - 1) temp = ' ';
		if (values[k] < 0)
			file << '(' << values[k] << ')' << temp;
		else file << values[k] << temp;
	}
	file << "\n->" << calculate() << "\n\n";

}
