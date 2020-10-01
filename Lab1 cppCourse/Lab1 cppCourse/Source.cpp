#include"Header.h"

void printArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%i %s", arr[i], " ");  //������ ����� n ��������� �������
	printf("\n");
}

int processArray(int* arr, int* res, int* x) {

	//srand(time(NULL));

	for (int i = 0; i < arr_N; i++)  //������������� ������� ������� �� 1 �� 10
		arr[i] = 1 + (rand() % 10);



	int counts_in_arr[res_N] = {};  //�������� ����� ������� - ���-�� ��������� ������� ����� � arr 
	for (int i = 0; i < arr_N; i++)
		++counts_in_arr[arr[i]];



	int most_frequent_element = 0;
	for (int i = 1; i < res_N; i++)
		if (counts_in_arr[i] > counts_in_arr[most_frequent_element])  //���������� ���� ����� ������ �������, 
			most_frequent_element = i;                                //��������� ������������������ ������


	int counter_in_res = 0;  //���-�� ��������� arr �������� 2 � ����� ���
	for (int i = 0; i < res_N; i++)
		if (counts_in_arr[i] >= 2)
			res[counter_in_res++] = i;

	*x = counter_in_res;  //�������� ��� � ���������, ����� �����, ������� ��������� res ��������

	return most_frequent_element; // ��� � ���
}

void matrix_init(float** matrix) {  //������� ������������� �������
	for (int i = 0; i < matrix_rows; i++)
		for (int j = 0; j < matrix_cols; j++)
			*(*(matrix+i)+j)= sin(i - j) + cos(i + j);
}

void print_2d_matrix(float** matrix) {  //������� ����� ������� (��������� ������)
	printf("%s", "[  ");
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++)
			printf("%14f %s", *(*(matrix + i) + j), "  ");
		if (i == matrix_rows - 1) printf("%s \n", "  ]");
		else printf("\n");
	}
}

void print_1d_matrix(float** matrix) { //����� ��� ��� �� �������, �� � ���� 1-������� ������� � �� ��������� �������
	
	float* matr_1d = new float[matrix_size];
	for (int l = 0; l < matrix_rows; l++)
		for (int k = 0; k < matrix_cols; k++)
			*(matr_1d + k + l * matrix_cols) = *(*(matrix + matrix_rows - l - 1) + k);
		
	printf("%s", "[  ");     //����� �������, ����� �����
	for (int k = 0; k < matrix_size; k++)
		printf("%f %s", *(matr_1d + k), "  ");
	printf("%s \n", "  ]");

	delete[] matr_1d;
}

void del_matrix(float** matrix){
	for (int i = 0; i < matrix_rows; i++)
		delete[] * (matrix + i);

	delete[] matrix;
}

char* strncat(char* dest, const char* src, size_t maxlen) {
	char* ptr = dest;
	while (*ptr != '\0') ++ptr; //�� ��������� ����� ptr ��������� �� ����� dest

	size_t count = 0;  //�������, ����� �� ��������� maxlen
	int k = 0;
	while (*(src + k) != '\0' && count < maxlen) { //���� �� ���������� src ��� �� �������� maxlen
		*ptr = *(src + k);
		ptr++;
		count++;
		k++;
	}

	*ptr = '\0'; //0-������ � ����� ����� ������

	return dest;
}

void test1() { //���� ��� ������� � 1-������� ���������
	printf("%s \n\n", "TEST 1");

	int int_array[arr_N];
	int res[res_N];
	int count_2;


	printf("%s \n", "init array");
	int most_frequent_element = processArray(int_array, res, &count_2);
	printf("%s \n", "after process array");
	printArray(int_array, arr_N);
	printf("%s \n", "result array");
	printArray(res, count_2);
	printf("%s %i \n\n\n", "most_frequent_element", most_frequent_element);
}

void test2() { //���� ��� ������� � ���������
	std::cout << "TEST2\n\n";
	float** matrix = new float* [matrix_rows];
	for (int i = 0; i < matrix_rows; i++)
		*(matrix+i) = new float[matrix_cols];

	matrix_init(matrix);
	printf("%s \n\n", "2d_matrix");
	print_2d_matrix(matrix);
	printf("%s \n\n", "\n\n1d_matrix");
	print_1d_matrix(matrix);
	printf("\n\n");
	

	del_matrix(matrix);


}

void test3() { //���� ��� ������� �� ��������

	char dest[256];

	//���� ��������� ������ � maxlen
	printf("%s \n", "input begin str");
	scanf("%s", &dest);
	printf("%s \n", "input maxlen");
	size_t maxlen = scanf("%i", &maxlen);

	char* str = strncat(dest, " world", maxlen);
	printf("%s \n %s \n", "result:", str);
}

