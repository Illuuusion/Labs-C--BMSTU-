#include "stdafx.h"
#include "mysort.h"

void swapElement(int* adress1, int* adress2){
	int save = *adress1;
	*adress1 = *adress2;
	*adress2 = save;
}

void bubbleSort(int* arr, unsigned count){
	for (unsigned i = 0; i < count; i++){
		for (unsigned j = i + 1; j < count; j++){
			if (arr[i] > arr[j]){
				swapElement(arr + i, arr + j);
			}
		}
	}
}

void shakerSort(int* arr, unsigned count){
	unsigned leftSide = 1;
	unsigned rightSide = count--;
	char key = TRUE;
	do{
		key = TRUE;
		for (unsigned i = leftSide; i < rightSide; i++){
			if (arr[i - 1] > arr[i]){
				swapElement(arr + i - 1, arr + i);
				key = FALSE;
			}
		}
		rightSide--;
		for (unsigned i = rightSide; i >= leftSide; i--){
			if (arr[i] < arr[i - 1]){
				swapElement(arr + i, arr + i - 1);
				key = FALSE;
			}
		}
		leftSide++;
	}while(key == FALSE);
}

void combSort(int* arr, unsigned count){
    int gap = count;
    char key = TRUE;
    while (gap != 1 || key == TRUE){
		gap /= SHRINK_FACTOR;
		key = FALSE;
        for (unsigned i = 0; i < count - gap; i++){
            if (arr[i] > arr[i+gap]){
				swapElement(arr + i, arr + i + gap);
                key = TRUE;
            }
        }
    }
}

void shellSort(int* arr, unsigned count){
	for (int s = count / 2; s > 0; s /= 2) {
		for (int i = s; i < count; i++) {
            for (int j = i - s; j >= 0 && arr[j] > arr[j + s]; j -= s) {
				swapElement(arr + j, arr + j + s); 
            }
        }
    }
}