//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

#define SUCCESS_READ 0
#define ERROR_READ 1

int input(int* start, int* finish, float* accuracy);
int check(int start, int finish, float accuracy);
float func(float start);
float step(int n);
float amount(int start, float accuracy);

int start = 0;
int finish = 0;
float accuracy = 0;

int main(){
  setlocale(LC_ALL, "RUS"); 
  float accuracy;
  if (input(&start, &finish, &accuracy) == SUCCESS_READ && check(start, finish, accuracy)){
    float res = amount(start, accuracy);
    printf("%.4f\n", res);
    getch();
  }
  else{
    printf("Error\n");
    getch();
  }
}

int input(int* start, int* finish, float* accuracy){
  printf("Enter the limits of integration and accuracy (E):\n");
  if (scanf("%d%d%f",start, finish, accuracy) == 3)
    return SUCCESS_READ;
  else
    return ERROR_READ;
}

int check(int start, int finish, float accuracy){
  return start < finish && accuracy < (finish - start);
}

float step(int n){
  float step = (float)(finish - start)/n;
  return step;
}

float func(float start){
  if (start < 0)
  printf("Error\n");
  else
  return log(start);
}

float amount(int start, float accuracy){
  float currentIntegral= 0;
  float previousIntegral = 0;
  int n = 1;
  float x = 0;
  float amount = 0;
  do{
    float h = step(n);
    previousIntegral = currentIntegral;
  for (int i = 0; i < n; i++){
      x = start + i*h;
      amount += func(x);
    }
    currentIntegral = amount*h;
    n *= 2;
  amount = 0;
    }while(fabs(currentIntegral - previousIntegral)>accuracy);
  return currentIntegral;
}
