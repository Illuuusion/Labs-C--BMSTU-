#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define SUCCESS 0
#define ERROR 1
#define MAX_SIZE 5
#define CORRECT_INPUT 2
#define LENGTH_SURNAME 12

typedef struct Student{
	char* surname;
	unsigned marks[MAX_SIZE];
	float average;
}student_t;

unsigned inputCountOfStudents();
student_t* groupOfSudents(unsigned count);
void inputSurnameAndMarks(student_t* group, unsigned count);
void swapElement(student_t* adress1, student_t* adress2);
void swapElementUnsigned(unsigned* adress1, unsigned* adress2);
void averageMarkOfStudent(student_t* group, unsigned count);
void deleteElement(student_t* group, unsigned count, unsigned index);
unsigned deleteStudentsByMarks(student_t* group, unsigned count);
void outputGroup(student_t* group, unsigned count);

int main(){
	unsigned count = inputCountOfStudents();
	student_t* group = groupOfSudents(count);
	inputSurnameAndMarks(group, count);
	averageMarkOfStudent(group, count);
	count = deleteStudentsByMarks(group, count);
	outputGroup(group, count);
	getch();
	free(group);
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
				printf("Mark must be integer type and positive!\n");
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

void averageMarkOfStudent(student_t* group, unsigned count){
	float average = 0;
	for (unsigned i = 0; i < count; i++){
		for (unsigned j = 0; j < MAX_SIZE; j++){
			average += group[i].marks[j];
		}
		group[i].average = (float) average / MAX_SIZE;
		average = 0;
	}
}

unsigned deleteStudentsByMarks(student_t* group, unsigned count){
	unsigned countOfTwo = 0;
	unsigned shift = 0;
	unsigned count1 = count;
	for (unsigned i = 0; i < count; i++){
		for (unsigned j = 0; j < MAX_SIZE; j++){
			if (group[i].marks[j] == 2){
				countOfTwo += 1;
				if (countOfTwo == 2){
					for (unsigned k = i; k < count; k++){
							group[k] = group[k + 1];
					}
					shift++;
					count -= shift;
					continue;
				}
			}
		}
	}
	return count;
}

void outputGroup(student_t* group, unsigned count){
	for (unsigned i = 0; i < count; i++){
		printf("%s\n", group[i].surname);
		for (unsigned j = 0; j < MAX_SIZE; j++){
			printf("%u ", group[i].marks[j]);
		}
		printf("\n");
		printf("%.2f", group[i].average);
		printf("\n\n");
	}
}

