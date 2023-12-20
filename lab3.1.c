//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>


#define SUCCESS_READ 0
#define ERROR_READ 1


int input(float* accuracy);
int factorial(int n);
double func(int n);
double amount(float accuracy);

float accuracy = 0;

int main(){
	setlocale(LC_ALL, "RUS");
	if (input(&accuracy) == SUCCESS_READ){
		double res = amount(accuracy);
		printf("%.4f", res);
		getch();
	}
	else{
		printf("Error\n");
		getch();
  }
}

int input(float* accuracy){
	printf("Ââåäèòå òî÷íîñòü ñóììû ñõîäÿùåãîñÿ áåñêîíå÷íîãî ðÿäà:\n");
	if (scanf("%f", accuracy) == 1){
		return SUCCESS_READ;
	}
	else{
		return ERROR_READ;
  }
}

int factorial (int n){
	if (n==0){
		return 1;
	}
	else{
		n = n*factorial(n-1);
		return n;
	}
}

double func(int n){
	return pow(-1.0, n) / factorial(n);
}



double amount(float accuracy){
	double previous = 0, current = 0;
	double amount = 0;
	int n = 0;
	double e = 0;
	do{
		previous = current;
		current = func(n);
		amount += current;
		n++;
		e = abs(current - previous);
	}while (e > accuracy);
	return amount;
}
