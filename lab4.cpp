#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>


#define SUCCESS 0
#define ERROR 1


int inputSizeOfArray();
float* allocationOfArrayMemory(int n);
void inputElementsOfArray(float* arr, int n);
int searchIndexOfMaxElem(float* arr, int n);
int searchIndexOfMinElem(float* arr, int n);
float searchSum(float* arr, int n, int indexMax, int indexMin);

int main(){
	float* arr;
	int n;
	n = inputSizeOfArray();
	arr = allocationOfArrayMemory(n);
	inputElementsOfArray(arr, n);
	int indexMax = searchIndexOfMaxElem(arr, n);
	int indexMin = searchIndexOfMinElem(arr, n);
	float amount = searchSum(arr, n, indexMax, indexMin);
	printf("%.3f\n", amount);
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

int searchIndexOfMaxElem(float* arr, int n){
	int index = 0;
	for (int i = 0; i < n; i++){
		if (arr[i]> arr[index]){
			index = i;
		}
	}
	return index;
}

int searchIndexOfMinElem(float* arr, int n){
	int index = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] < arr[index]){
			index = i;
		}
	}
	return index;
}

float searchSum(float* arr, int n, int indexMax, int indexMin){
	float sum = 0;
	for (int i = indexMax + 1; i < n; i++){
		if (arr[i] > (arr[indexMax]+indexMin)/2)
			sum += arr[i];
	}
	return sum;
}