#define _CRT_SECURE_NO_WARNINGS
#include"Telephone.h"
#include"Fraction.h"
#include"Matrix.h"
#include"Vector.h"



int Fraction::count = 0;

int main() {

	/*
	Matrix matr(3, 5);
	matr.Init();
	std::cout << matr << '\n';
	Vector vect = matr.conv();
	std::cout << vect << '\n';
	*/


	//==================================================================================================================================




	/*
	Fraction f1(3, 5);
	Fraction f2(5, 11);
	Fraction f3(9, 17);

	f1.Print();
	f2.Print();
	f3.Print();

	Fraction f4 = f1 + f2;
	Fraction f5 = f2 - f3;
	Fraction f6 = f3 * f4;
	Fraction f7 = f4 / f5;

	f4.Print();
	f5.Print();
	f6.Print();
	f7.Print();

	char dest[256];
	printf("%s \n", "input fraction");
	scanf("%s", &dest);

	Fraction::printAsFraction(dest);
	Fraction::printAsFraction(0.65);
	*/




	//==================================================================================================================================





	/*
	Telephone* t1 = new Telephone("sumsung", "071-348-59-91", "071-348-59-90", 150);
	Telephone* t2 = new Telephone();
	t2->setModel("xiaomi");
	t2->setNumber("071-236-72-99");
	t2->setLCN("071-348-59-91");
	t2->setScore(200);

	std::string t2_num = t2->getNumber();

	char num1[256], num2[256];
	for (int k = 0; k < 3; k++) {
		printf("%i %s \n", k + 1, " iteration");

		t1->call(t2_num, 12);

		printf("%s \n", "input number 1");
		scanf("%s", &num1);
		t1->call(num1, 6);

		printf("%s \n", "input number 2");
		scanf("%s", &num2);
		t2->call(num2, 8);

	}

	t1->serialize();
	t2->serialize();

	std::cout << *t1;
	*/

	return 0;
}