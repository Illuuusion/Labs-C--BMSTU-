#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>

#define SUCCESS 0
#define ERROR 1
#define CORRECT_INPUT 2
#define NOT_POSITIVE < 0

int inputNumberOfRowsOfMatrix();
int inputNumberOfColumnsOfMatrix();
float** allocationOfMatrixMemory(int n, int m);
void inputElementsOfMatrix(float** mat, int n, int m);
void swapElement(float* adress1, float* adress2);
void sortMatrixSnake(float** mat, int n, int m);
void outputElementsOfMatrix(float** mat, int n, int m);
void freeMatrix(float** mat, int n);

int main() {
	int rows = inputNumberOfRowsOfMatrix();
	int columns = inputNumberOfColumnsOfMatrix();
	float** mat = allocationOfMatrixMemory(rows, columns);
	inputElementsOfMatrix(mat, rows, columns);
	sortMatrixSnake(mat, rows, columns);
	outputElementsOfMatrix(mat, rows, columns);
	freeMatrix(mat, rows);
	_getch();
	return SUCCESS;
}

int inputNumberOfRowsOfMatrix() {
	int n;
	char d;
	printf("Enter number of rows of matrix:\n");
	while (scanf("%d%c", &n, &d) != CORRECT_INPUT && d != '\n' || n NOT_POSITIVE) {
		printf("Rows of matrix must be integer type and positive\n");
		fflush(stdin);
	}
	return n;
}

int inputNumberOfColumnsOfMatrix() {
	int n = 0;
	char d;
	printf("Enter number of columns of matrix:\n");
	while (scanf("%d%c", &n, &d) != CORRECT_INPUT && d != '\n' || n NOT_POSITIVE) {
		printf("Columns of matrix must be integer type and positive\n");
		fflush(stdin);
	}
	return n;
}

float** allocationOfMatrixMemory(int n, int m) {
	float** mat = (float**)malloc(n * sizeof(float**));
	for (int i = 0; i < n; i++) {
		mat[i] = (float*)malloc(m * sizeof(float*));
	}
	return mat;
}

void inputElementsOfMatrix(float** mat, int n, int m) {
	char d;
	printf("Enter element of matrix:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			while (scanf("%f%c", &mat[i][j], &d) != CORRECT_INPUT || d != '\n') {
			printf("Element of this matrix must be float type\n");
			fflush(stdin);
			}
		}
	}
}

void swapElement(float* adress1, float* adress2) {
	float save = *adress1;
	*adress1 = *adress2;
	*adress2 = save;
}

void sortMatrixSnake(float** mat, int n, int m) {
	for (int p = 0; p < (n * m); p++) {
		for (int j = 0; j < m; j++) {
			if (j % 2 == 0) {
				for (int i = 0; i < n; i++) {
					if (i == n - 1) {
						if (mat[i][j] > mat[i][j + 1] && j != m - 1) {
							swapElement(mat[i] + j, mat[i] + j + 1);
						}
					}
					else {
						if (mat[i][j] > mat[i + 1][j]) {
							swapElement(mat[i] + j, mat[i + 1] + j);
						}
					}
				}
			}
			else {
				for (int i = n - 1; i > -1; i--) {
					if (i == 0) {
						if (mat[i][j] > mat[i][j + 1] && j != m - 1) {
							swapElement(mat[i] + j, mat[i] + j + 1);
						}
					}
					else {
						if (mat[i][j] > mat[i - 1][j]) {
							swapElement(mat[i] + j, mat[i - 1] + j);
						}
					}
				}
			}
		}
	}
}

void outputElementsOfMatrix(float** mat, int n, int m) {
	printf("Transposed Matrix:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		printf("%.3f  ", mat[i][j]);
		}
		printf("\n");
	}
}

void freeMatrix(float** mat, int n) {
	for (int i = 0; i < n; i++)
		free(mat[i]);
	free(mat);
}
