#include"Header.h"


void printArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%i %s", arr[i], " ");  
	printf("\n");
}

int processArray(int* arr, int* res, int* x) {

	

	for (int i = 0; i < arr_N; i++)  
		arr[i] = 1 + (rand() % 10);



	int counts_in_arr[res_N] = {};  
	for (int i = 0; i < arr_N; i++)
		++counts_in_arr[arr[i]];



	int most_frequent_element = 0;
	for (int i = 1; i < res_N; i++)
		if (counts_in_arr[i] > counts_in_arr[most_frequent_element])   
			most_frequent_element = i;                               


	int counter_in_res = 0;  
	for (int i = 0; i < res_N; i++)
		if (counts_in_arr[i] >= 2)
			res[counter_in_res++] = i;

	*x = counter_in_res;  

	return most_frequent_element; 
}

void matrix_init(Matrix<float>&M) {
	int r = M.getR();
	int c = M.getC();
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			M.setAt(i,j ,sin(i - j) + cos(i + j));
}

void print_2d_matrix(Matrix<float>&M) {
	int r = M.getR();
	int c = M.getC();

	printf("%s", "[  ");
	for (int i = 0; i <r; i++) {
		for (int j = 0; j < c; j++)
			printf("%14f %s", M.at(i, j), "  ");
		if (i == r - 1) printf("%s \n", "  ]");
		else printf("\n");
	}
}

void print_1d_matrix(Matrix<float>&M) {
	int r = M.getR();
	int c = M.getC();

	Vector<float> V(r*c);
	
	for (int l = 0; l < r; l++)
		for (int k = 0; k < c; k++)
			V[k + l * c] = M.at(r - l - 1, k);

	printf("%s", "[  ");     
	for (int k = 0; k < r*c; k++)
		printf("%f %s", V[k], "  ");
	printf("%s \n", "  ]");

}


char* strncat(char* dest, const char* src, size_t maxlen) {
	char* ptr = dest;
	while (*ptr != '\0') ++ptr; 

	size_t count = 0;  
	int k = 0;
	while (*(src + k) != '\0' && count < maxlen) { 
		*ptr = *(src + k);
		ptr++;
		count++;
		k++;
	}

	*ptr = '\0'; 

	return dest;
}

void test1() { 
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

void test2() { 
	std::cout << "TEST2\n\n";
	Matrix<float> M(matrix_cols, matrix_rows);

	matrix_init(M);
	printf("%s \n\n", "2d_matrix");
	print_2d_matrix(M);
	printf("%s \n\n", "\n\n1d_matrix");
	print_1d_matrix(M);
	printf("\n\n");

}

void test3() { 

	char dest[256];

	
	printf("%s \n", "input begin str");
	scanf("%s", &dest);
	printf("%s \n", "input maxlen");
	size_t maxlen = scanf("%i", &maxlen);

	char* str = strncat(dest, " world", maxlen);
	printf("%s \n %s \n", "result:", str);
}