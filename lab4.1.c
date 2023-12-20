//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>


#define SUCCESS 0
#define ERROR 1


int inputSizeOfArray();
float* allocationOfArrayMemory(int n);
void inputElementsOfArray(float* arr, int n);
float searchMaxElem(float* arr, int n);
float searchMinElem(float* arr, int n);
float searchSum(float* arr, int n, float MaxPlusMin);

float* arr;
int n;

int main(){
	n = inputSizeOfArray();
	float* arr = allocationOfArrayMemory(n);
	inputElementsOfArray(arr, n);
	float MaxElement = searchMaxElem(arr, n);
	float MinElement = searchMinElem(arr, n);
	float SumMaxMin = (float)((MaxElement + MinElement)/2);
	float amount = searchSum(arr, n, SumMaxMin);
	printf("%.3f\n", amount);
	getch();
	free(arr);
	return SUCCESS;
}

int inputSizeOfArray(){
	int n = 0;
	printf("Enter size of array\n");
	if (scanf("%d", &n) == 1)
	return n;
	else
	printf("Size of array must be integer type\n");
	return ERROR;
}

float* allocationOfArrayMemory(int n){
	float* arr = (float*)malloc(n * sizeof(float));
	if (arr == NULL)
	printf("Error\n");
	else
	return arr;
}

void inputElementsOfArray(float* arr, int n){
	printf("Enter element of array\n");
	for (int i = 0; i < n; i++){
		if (scanf("%f", &arr[i])!= 1)
		printf("Element of this array must be float type\n");
	}
}

float searchMaxElem(float* arr, int n){
	int MaxElement = arr[0];
	for (int i = 1; i < n; i++){
		if (arr[i]> MaxElement){
			MaxElement = arr[i];
		}
	}
	return MaxElement;
}

float searchMinElem(float* arr, int n){
	int MinElement = arr[0];
	for (int i = 1; i < n; i++){
		if (arr[i]< MinElement){
			MinElement = arr[i];
		}
	}
	return MinElement;
}

float searchSum(float* arr, int n, float MaxPlusMin){
	float sum = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] > MaxPlusMin)
		sum += arr[i];
	}
	return sum;
}
