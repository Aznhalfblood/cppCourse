#include"CustomExpEval.h"
#include"Summator.h"
#include"Multiplier.h"



int main() {
	const int n1 = 4;
	const int n2 = 6;
	double arr1[n1] = { 50,40,-10,2 };
	double arr2[n1] = { -0.5, -8, 1.5, 16 };
	double arr3[n2] = { 2.6, -8.1, 13.2, 1.5, 3.4, -4 };

	CustomExpEval obj1(n1);
	for (int k = 0; k < n1; ++k)
		obj1.setOperand(k, arr1[k]);

	Multiplier obj2(n1);
	Summator obj3(n2);

	obj2.setOperands(arr2, n1);
	obj3.setOperands(arr3, n2);

	obj1.logToScreen();
	obj2.logToScreen();
	obj3.logToScreen();

	obj1.logToFile("1.txt");
	obj2.logToFile("2.txt");
	obj3.logToFile("3.txt");



}