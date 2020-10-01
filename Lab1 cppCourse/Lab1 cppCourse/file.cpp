#include"Header.h"


int main() {

	test1();
	test2();

	//можно проверять strncat для различных dest и maxlen
	printf("%s \n", "TEST 3");
	do {
		
		printf("%s \n", "continue?  (yes - 1, no - 0)"); //работает, пока не введем 0
		int cont=scanf("%i", &cont);
		printf("\n");
		if (!cont) break;
		test3();
	} while (true);

	return 0;
}


