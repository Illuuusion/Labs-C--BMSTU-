#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>

#define SUCCESS 0
#define ERROR 1
#define NULL 0 

int inputSizeOfArray();
float* allocationOfArrayMemory(int n);
void inputElementsOfArray(float* arr, int n);
int countOfZero(float* arr, int n);
void swapElement(float* arr, int a, int b);
void sortArrayByModuleAscend(float* arr, int n, int countzero);
void sortArrayPlusMinus(float* arr, int n);
void sortArrayZero(float* arr, int n);
void outputElementsOfArray(float* arr, int n);

float *arr;
int n;

int main(){
	n = inputSizeOfArray();
	float* arr = allocationOfArrayMemory(n);
	inputElementsOfArray(arr, n);
	int czero = countOfZero(arr, n);
	sortArrayZero(arr, n);
	sortArrayByModuleAscend(arr, n, czero);
	sortArrayPlusMinus(arr, n);
	outputElementsOfArray(arr, n);
	free(arr);
	getch();
	return SUCCESS;
}

int inputSizeOfArray(){
	int n = 0;
	char d;
	printf("Enter size of array:\n");
	while (scanf("%d%c", &n, &d) != 2 || d != '\n'){
		printf("Size of array must be integer type!\n");
		scanf("%d%c", &n, &d);
		fflush(stdin);
	}
	return n;
}

float* allocationOfArrayMemory(int n){
	return (float*)malloc(n * sizeof(float));
}

void inputElementsOfArray(float* arr, int n){
	char d;
	printf("Enter elemenst of array:\n");
	for (int i = 0; i < n; i++){
		while (scanf("%f%c", &arr[i], &d)!= 2|| d != '\n'){
			printf("Element of this array must be float type!\n");
			scanf("%f%c", &arr[i], &d);
			fflush(stdin);
		}
	}
}

int countOfZero(float* arr, int n){
	int sum = 0; 
	for (int i = 0; i < n; i++){
		if (arr[i] == 0)
		sum += 1;
	}
	return sum;
}


void swapElement(float* arr, int a, int b){
	float save = arr[a];
	arr[a] = arr[b];
	arr[b] = save;
}

void sortArrayByModuleAscend(float* arr, int n, int countzero){
	for (int i = 0; i < n - 1 - countzero; i++){
		for (int m = i + 1; m < n - countzero; m++){
			if (fabs(arr[m]) < fabs(arr[i]))
			swapElement(arr, i, m);
		}
	}
}

void sortArrayPlusMinus(float* arr, int n){
	for (int i = 0; i < n - 1; i++){
		for (int m = i + 1; m < n; m++){
			if (arr[i] < 0 && arr[m] > 0)
			swapElement(arr, i, m);
			else if (arr[i] < 0 && arr[m] < 0 && arr[i] < arr[m])
			swapElement(arr, i, m);
		}
	}
}

void sortArrayZero(float* arr, int n){
	for (int i = 0; i < n - 1; i++){
		for (int m = i + 1; m < n; m++){
			if (arr[i] == 0 && arr[m]!=0)
			swapElement(arr, i, m);
		}
	}
}
void outputElementsOfArray(float* arr, int n){
	printf("Sorted Array:\n");
	for (int i = 0; i < n; i++)
	printf("%.3f\n", arr[i]);
}




