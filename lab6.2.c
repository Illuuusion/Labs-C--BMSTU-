//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>

#define SUCCESS 0
#define ERROR 1
#define NULL 0 

int inputNumberOfRowsOfMatrix();
int inputNumberOfColumnsOfMatrix();
float** AllocationOfMatrixMemory(int n, int m);
void inputElementsOfMatrix(float** mat, int n, int m);
float* searchMaxElem(float** mat, int n, int m);
float* searchMinElem(float** mat, int n, int m);
void swapElement(float* adress1, float* adress2);
void outputElementsOfMatrix(float** mat, int n, int m);
void freeMatrix(float** mat, int n);

int main(){
	 int rows = inputNumberOfRowsOfMatrix();
	 int columns = inputNumberOfColumnsOfMatrix();
	 float** mat = AllocationOfMatrixMemory(rows, columns);
	 inputElementsOfMatrix(mat, rows, columns);
	 float* MaxElem = searchMaxElem(mat, rows, columns);
	 float* MinElem = searchMinElem(mat, rows, columns);
	 swapElement(MaxElem, MinElem);
	 outputElementsOfMatrix(mat, rows, columns);
	 freeMatrix(mat, rows);
	 getch();
	 return SUCCESS;
}

int inputNumberOfRowsOfMatrix(){
	int n = 0;
	char d;
	printf("Enter number of rows of matrix:\n");
	while (scanf("%d%c", &n, &d) != 2 || d != '\n' || n < 0){
		printf("Rows of matrix must be integer type and positive\n");
		scanf("%d%c", &n, &d);
		fflush(stdin);
	}
	return n;
}

int inputNumberOfColumnsOfMatrix(){
		int n = 0;
	char d;
	printf("Enter number of columns of matrix:\n");
	while (scanf("%d%c", &n, &d) != 2 || d != '\n' || n < 0){
		printf("Columns of matrix must be integer type and positive\n");
		scanf("%d%c", &n, &d);
		fflush(stdin);
	}
	return n;
}

float** AllocationOfMatrixMemory(int n, int m){
	float** mat = (float**)malloc(n*sizeof(float**));
	for (int i = 0; i < n; i++){
		mat[i] = (float*)malloc(m*sizeof(float*));
	}
	return mat;
}

void inputElementsOfMatrix(float** mat, int n, int m){
	char d;
	printf("Enter element of matrix:\n");
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < m; j++){
			while (scanf("%f%c", &mat[i][j], &d) !=2 || d != '\n'){
				printf("Element of this matrix must be float type\n");
				scanf("%d%c", &n, &d);
				fflush(stdin);
			}
		}
	}
}

float* searchMaxElem(float** mat, int n, int m){
	float* MaxElem = mat[0];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m - 1 - i; j++){
			if (*MaxElem < mat[i][j])
				MaxElem = mat[i]+ j;
		}
	}
	return MaxElem;
}

float* searchMinElem(float** mat, int n, int m){     
	float* MinElem = mat[n - 1]+ m - 1;	             
	for (int i = n - 1; i > 0; i--){
 		for (int j = m - 1; j > m - i - 1; j--){
 			if (*MinElem > mat[i][j])				
				MinElem = mat[i] + j;
  		}
	}
	return MinElem;
}

void swapElement(float* adress1, float* adress2){
	float save = *adress1;
	*adress1 = *adress2;
	*adress2 = save;
}

void outputElementsOfMatrix(float** mat, int n, int m){
	printf("Transposed Matrix:\n");
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < m; j++){
			printf("%-.3f  ", mat[i][j]);
		}
		printf("\n");
	}
}

void freeMatrix(float** mat, int n){
	for (int i = 0; i < n; i++){
		free(mat[i]);
	}
	free(mat);
}
