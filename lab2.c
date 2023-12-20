//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>


#define SUCCESS_READ 0
#define ERROR_READ -1

int input(float* start, float* finish, int* iteration);
float func(float i);
void outputFor(float start, float finish, float increase);
void outputWhile(float start, float finish, float increase);
void outputDoWhile(float start, float finish, float increase);

int main(){
	float start = 0, finish = 0;
	int iteration = 0;
	if ((input(&start, &finish, &iteration) == SUCCESS_READ) && (start < finish) && (iteration>=2) && (start != 0)){
		float increase = (finish - start)/(iteration - 1);
		outputFor(start, finish, increase);
		outputWhile(start, finish, increase);
		outputDoWhile(start, finish, increase);
	}
	else{
		printf("Error\n");
		return 1;
	}
	getch();
}
int input(float* start, float* finish, int* iteration) {
	printf("Enter left and right boundaries of the interval, as well as the number of iterations:\n");
	if (scanf("%f %f %d", start, finish, iteration) == 3) {
		return SUCCESS_READ;
    }
	else {
		return ERROR_READ;
	}
}

float func(float i){
	float y;
	y = sin(i) * sin(i) / i;
	return y;
}

void outputFor(float start, float finish, float increase){
	printf("For\nx\t ");
	for (float i = start; i <= finish; i += increase){
		printf("|%7.3f", i);
	}
	printf("\nf(x)\t ");
	for (float i = start; i <= finish; i += increase){
		float result = func(i);
		printf("|%7.3f", result);
	}
}


void outputWhile(float start, float finish, float increase){
	printf("\nWhile\nx\t ");
	float i = start;
	while (i <= finish){
		printf("|%7.3f", i);
		i += increase;
	}
	printf("\nf(x)\t ");
	i = start;
	while (i <= finish){
		float result = func(i);
		printf("|%7.3f", result);
		i += increase;
	}
}


void outputDoWhile(float start, float finish, float increase){
	printf("\nDoWhile\nx\t ");
	float i = start;
	do{
		printf("|%7.3f", i);
		i += increase;
	}while(i <= finish);
	printf("\nf(x)\t ");
	i = start;
	do{
		float result = func(i);
		printf("|%7.3f", result);
		i += increase;
	}while (i <= finish);
}
