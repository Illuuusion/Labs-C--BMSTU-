//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SUCCESS 0
#define ERROR 1
#define FIRST_SIZE_OF_ARRAY 5
#define FIRST_SIZE_OF_STRING 5
#define SIZE_OF_CHAR 1

unsigned inputDataFromFile(char** arr);
void creatingNewFile(char**arr, unsigned count);
void test();

int main(){
	char** arr = (char**)malloc(sizeof(char*) * FIRST_SIZE_OF_ARRAY);
	unsigned count = inputDataFromFile(arr); 
	creatingNewFile(arr, count);
	return SUCCESS;
}


unsigned inputDataFromFile(char** arr) {
	int maxSize = FIRST_SIZE_OF_STRING;
	char* buffer = 0;
	unsigned i = 0;
	FILE* file = fopen("fileforlab.txt", "r");
	if (file){
		fseek(file, 0, SEEK_END);
		long length = ftell(file);
		fseek(file, 0, SEEK_SET);
		buffer = (char*) malloc(sizeof(char) * (length+1));
		buffer[length] = '\0';
		while (fgets(buffer, length, file)){ 
			arr[i] = (char*)malloc((length+1)* sizeof(char));
			strncpy(arr[i], buffer, strcspn(buffer, "\n"));
			arr[i][strcspn(buffer, "\n")] = '\0';
			if (strlen(arr[i]) == 0){
				i--;
			}
			i++;
		}
		fclose(file);
	}
	return i;
}

void creatingNewFile(char** arr, unsigned count) {
	FILE* file = fopen("newfile.txt", "w");
	int j = 0;
	for (int i = 0; i < count; i++) {
		if (strlen(arr[i])) {
			fprintf(file, "%d. %s\n", i + 1 - j, arr[i]);
		}
		else {
			j++;
		}
	}
	fclose(file);
}

void test(){
	FILE* file = fopen("fileforlab.txt", "w");
	fclose(file);
}
