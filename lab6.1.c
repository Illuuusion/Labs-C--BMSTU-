#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>

#define SUCCESS 0
#define ERROR 1


int inputSizeOfMatrix();
float** AllocationOfMatrixMemory(int n);
void inputElementsOfMatrix(float** mat, int n);
void swapElement(float* adress1, float* adress2);
void transpositionOfMatrix(float** mat, int n);
void outputElementsOfMatrix(float** mat, int n);
void freeMatrix(float** mat, int n);

int main(){
	int n = inputSizeOfMatrix();
	float** mat = AllocationOfMatrixMemory(n);
	inputElementsOfMatrix(mat, n);
	transpositionOfMatrix(mat, n);
	outputElementsOfMatrix(mat, n);
	getch();
	freeMatrix(mat, n);
	return SUCCESS;
}

int inputSizeOfMatrix(){
	int n = 0;
	char d;
	printf("Enter sizes of square matrix\n");
	while (scanf("%d%c", &n, &d) != 2 || d != '\n'){
		printf("Sizes of matrix must be integer type\n");
		scanf("%d%c", &n, &d);
		fflush(stdin);
	}
	return n;
}

float** AllocationOfMatrixMemory(int n){
	float** mat = (float**)malloc(n*sizeof(float**));
	for (int i = 0; i < n; i++){
		mat[i] = (float*)malloc(n*sizeof(float*));
	}
	return mat;
}

void inputElementsOfMatrix(float** mat, int n){
	char d;
	printf("Enter element of matrix:\n");
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j++){
			while (scanf("%f%c", &mat[i][j], &d) !=2 || d != '\n'){
				printf("Element of this matrix must be float type\n");
				scanf("%d%c", &n, &d);
				fflush(stdin);
			}
		}
	}
}

void swapElement(float* adress1, float* adress2){
	float save = *adress1;
	*adress1 = *adress2;
	*adress2 = save;
}

void transpositionOfMatrix(float** mat, int n){
	for (int i = 0; i < n - 1 ; i++){
		for (int j = 0; j < n- 1 - i; j++){
			swapElement(mat[i] + j, mat[n - j - 1] + n - i - 1);
		}
	}
}

void outputElementsOfMatrix(float** mat, int n){
	printf("Transposed Matrix:\n");
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j++){
			printf("%.3f  ", mat[i][j]);
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

