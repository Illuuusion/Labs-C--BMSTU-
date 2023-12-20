#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

#define SUCCESS 0
#define ERROR 1
#define MAX_SIZE 5
#define CORRECT_INPUT 2
#define LENGTH_SURNAME 12

typedef struct Student{
	char* surname;
	unsigned marks[MAX_SIZE];
}student_t;

unsigned inputCountOfStudents();
student_t* groupOfSudents(unsigned count);
void inputSurnameAndMarks(student_t* group, unsigned count);
void swapElement(student_t* adress1, student_t* adress2);
void swapElementUnsigned(unsigned* adress1, unsigned* adress2);
void sortStudents(student_t* group, unsigned count);
void sortStudentsByMarks(student_t* group, unsigned count);
void sortStudentsBySurnames(student_t* group, unsigned count);
void outputGroup(student_t* group, unsigned count);

int main(){
	unsigned count = inputCountOfStudents();
	student_t* group = groupOfSudents(count);
	inputSurnameAndMarks(group, count);
	sortStudentsBySurnames(group, count);
	sortStudentsByMarks(group, count);
	outputGroup(group, count);
	getch();
	return SUCCESS;
}

unsigned inputCountOfStudents(){
	unsigned n = 0;
	char d;
	printf("Enter number of students:\n");
	while (scanf("%u%c", &n, &d) != CORRECT_INPUT && d != '\n' && n < 0){
		printf("Count of students must be integer type and positive\n");
		fflush(stdin);
	  }
	  return n;
}

student_t* groupOfSudents(unsigned count){
	return (student_t*)malloc(count * sizeof(student_t));
}

void inputSurnameAndMarks(student_t* group, unsigned count){
	char d;
	for (unsigned i = 0; i < count; i++){
		group[i].surname = (char*)malloc(LENGTH_SURNAME * sizeof(char));
		printf("Enter surname of student:\n");
		gets(group[i].surname);
		printf("Enter marks of student:\n");
		for (unsigned j = 0; j < MAX_SIZE; j++){
			char d;
			while (scanf("%u%c", (group+i) -> marks+j, &d) != CORRECT_INPUT || d != '\n'){
				printf("Mark must be integer type and positive");
				fflush(stdin);
			}
		}
	}
}

void swapElement(student_t* adress1, student_t* adress2){
	student_t save = *adress1;
	*adress1 = *adress2;
	*adress2 = save;
}

void swapElementUnsigned(unsigned* adress1, unsigned* adress2){
	unsigned save = *adress1;
	*adress1 = *adress2;
	*adress2 = save;
}

void sortStudentsMarks(student_t* group, unsigned count){
	for (unsigned i = 0; i < count; i++){
		for (unsigned j = 0; j < MAX_SIZE; j++){
			for (unsigned k = j+1; k < MAX_SIZE; k++){
				if (group[i].marks[j] > group[i].marks[k]){
					swapElementUnsigned((group+ i) -> marks + j, (group+ i) -> marks + k);
				}
			}
		}
	}
}

void sortStudentsByMarks(student_t* group, unsigned count){
	sortStudentsMarks(group, count);
	for (unsigned i = 0; i < count; i++){
		for (unsigned j = i + 1; j < count; j++){
			if (group[i].marks[0] < group[j].marks[0]){
				swapElement(group + i, group + j);
			}
		}
	}
}

void sortStudentsBySurnames(student_t* group, unsigned count){
	sortStudentsMarks(group, count);
	for (unsigned i = 0; i < count; i++){
		for (unsigned j = i + 1; j < count; j++){
			if (strcmp(group[i].surname, group[j].surname) > 0){
				swapElement(group + i, group + j);
			}
		}
	}
}

void outputGroup(student_t* group, unsigned count){
	for (unsigned i = 0; i < count; i++){
		printf("%s\n", group[i].surname);
		for (unsigned j = 0; j < MAX_SIZE; j++){
			printf("%u ", group[i].marks[j]);
		}
		printf("\n\n");
	}
}

