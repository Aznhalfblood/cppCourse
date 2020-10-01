#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <random>
#include <time.h>
#include <math.h>
#include <iostream>



const int arr_N = 20;
const int res_N = 11;

const int matrix_rows = 5;
const int matrix_cols = 3;
const int matrix_size = 15;

int processArray(int* arr, int* res, int* x);
void printArray(int* arr, int n);

void matrix_init(float** matrix);
void print_2d_matrix(float** matrix);
void print_1d_matrix(float** matrix);
void del_matrix(float** matrix);

char* strncat(char* dest, const char* src, size_t maxlen);

void test1();
void test2();
void test3();


