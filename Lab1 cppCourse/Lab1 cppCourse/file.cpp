#include"Header.h"


int main() {

	test1();
	test2();

	//����� ��������� strncat ��� ��������� dest � maxlen
	printf("%s \n", "TEST 3");
	do {
		
		printf("%s \n", "continue?  (yes - 1, no - 0)"); //��������, ���� �� ������ 0
		int cont=scanf("%i", &cont);
		printf("\n");
		if (!cont) break;
		test3();
	} while (true);

	return 0;
}


