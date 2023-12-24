#ifndef _MYSORT_H_
#define _MYSORT_H_
#define TRUE '1'
#define FALSE '0'
#define SHRINK_FACTOR 1.2473309
void swapElement(int* adress1, int* adress2);
void bubbleSort(int* arr, unsigned count);
void shakerSort(int* arr, unsigned count);
void combSort(int* arr, unsigned count);
void shellSort(int* arr, unsigned count);
#endif