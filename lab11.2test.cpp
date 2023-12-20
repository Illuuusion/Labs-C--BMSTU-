#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_LEN_STR 256
#define COUNT_ANIME_FOR_START 10
#define EXIT 5
#define SIZE_BUFF 1024
#define SUCCESS 1
#define ERROR 0
#define MIN 0
#define CORRECT_INPUT 1
#define MAX 6
#define ADD_ANIME 1
#define OUTPUT_ANIME_LIST 2
#define SORT_ANIME 3
#define DELETE_ANIME 4

typedef struct Anime {
    char name[MAX_LEN_STR];
    char author[MAX_LEN_STR];
    int seasons;
    int rank;
}anime;

void outputMenu();
int inputCase(int* menuItem);
void warning();
void actionOfPerson(int menuItem);
void addTheAnimeToTheEndOfFile();
void addParamsToStruct(anime* p);
int enterArrOfAnimeFromFile(FILE* f, anime* arr);
void outputAnimeOnScreen();
void sortAnimeByRank();
void sortArray(anime* arr, int numberOfBooks);
int compareByRank(anime* s1, anime* s2);
void sort(anime* movie, int count, int(*compare)(anime*, anime*));
void swap(anime* s1, anime* s2);
void addToTheFile(anime* arr, int count);
void deleteTheEnter(anime* arr, int count);
void deleteByAuthor();
void deleteAnime(anime* arr, int* numberOfBooks, int* i);

int main() {
    int menu;
    outputMenu();

    for (int key = inputCase(&menu); menu != EXIT; key = inputCase(&menu)) {
        if (!key) {
            warning();
        }
        else {
            actionOfPerson(menu);
        }

    }
    return 0;
}

void outputMenu() {
    printf("Choose the action:\n");
    printf("1. Add the anime movie to the end of file\n");
    printf("2. Display the anime movies on the screen\n");
    printf("3. Sort anime movies\n");
    printf("4. Delete the anime movie\n");
    printf("5. Exit\n");
}

int inputCase(int* menuItem) {
    char BUF[SIZE_BUFF];

    if (scanf("%d", menuItem) == CORRECT_INPUT && *menuItem > MIN && *menuItem < MAX) {
        fgets(BUF, SIZE_BUFF, stdin);
        return SUCCESS;
    }
    fgets(BUF, SIZE_BUFF, stdin);
    return ERROR;
}

void warning() {
    printf("Incorrect Input\n");
    printf("Try again\n");
}

void actionOfPerson(int menuItem) {
    switch (menuItem) {
	case ADD_ANIME: addTheAnimeToTheEndOfFile(); break;
	case OUTPUT_ANIME_LIST: outputAnimeOnScreen(); break;
	case SORT_ANIME: sortAnimeByRank(); break;
	case DELETE_ANIME: deleteByAuthor(); break;
    }
}

void deleteByAuthor() {
    char searchAuthor[MAX_LEN_STR];

    printf("Enter The author:\n");
    gets_s(searchAuthor, MAX_LEN_STR);

    FILE* f = fopen("my_file.txt", "r");
	anime* arr = (anime*)calloc(COUNT_ANIME_FOR_START, sizeof(anime));
    int numberOfAnime = enterArrOfAnimeFromFile(f, arr);
    fclose(f);
    for (int i = 0; i < numberOfAnime; i++) {
        if (!strcmp(arr[i].author, searchAuthor)) {
            deleteAnime(arr, &numberOfAnime, &i);
            i--;
        }
    }
    addToTheFile(arr, numberOfAnime);
}
void deleteAnime(anime* arr, int* numberOfAnime, int*i) {
    for (int j = *i; j + 1 < *numberOfAnime; j++) {
        arr[j] = arr[j+1];
    }
    (*numberOfAnime)--;
}

void sortAnimeByRank() {
    FILE* f = fopen("my_file.txt", "r");
    anime* arr = (anime*)calloc(COUNT_ANIME_FOR_START, sizeof(anime));
    int numberOfAnime = enterArrOfAnimeFromFile(f, arr);
    fclose(f);
    sort(arr, numberOfAnime, compareByRank);
    addToTheFile(arr, numberOfAnime);
}


void sort(anime* animeMovie, int count, int(*compare)(anime*, anime*)) {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (compare(animeMovie + i, animeMovie + j) > 0) {   // s2 < s1
                swap(animeMovie + i, animeMovie + j);
            }
        }
    }
}
void swap(anime* s1, anime* s2) {
    anime temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int compareByRank(anime* s1, anime* s2) {
    return s1->rank - s2->rank;
}

void addToTheFile(anime* arr, int count) {
    FILE* f = fopen("my_file.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s\n%s\n%d\n%d\n", arr[i].name, arr[i].author, arr[i].seasons, arr[i].rank);
    }
    fclose(f);
}

void outputAnimeOnScreen() {
    FILE* f = fopen("my_file.txt", "r");
    anime* arr = (anime*)calloc(COUNT_ANIME_FOR_START, sizeof(anime));
    int numberOfAnime = enterArrOfAnimeFromFile(f, arr);
    for (int i = 0; i < numberOfAnime; i++) {
		printf("\n----------------\n");
        printf("%s\n", arr[i].name);
        printf("%s\n", arr[i].author);
		printf("%d\n", arr[i].seasons);
        printf("%d", arr[i].rank);
    }
    printf("\n----------------\n");
    fclose(f);
}

int enterArrOfAnimeFromFile(FILE* f, anime* arr) {
    char BUFF[SIZE_BUFF];
    int numberOfAnime = 0;
    int maxAnime = COUNT_ANIME_FOR_START;
    for (int i = 0; !feof(f); i ++) {
        if (numberOfAnime == maxAnime) {
            maxAnime *= 2;
            arr = (anime*)realloc(arr, sizeof(anime) * maxAnime);
        }
        fgets(arr[i].name, MAX_LEN_STR, f);
        if (arr[i].name[0] == '\0') {
            break;
        }
        fgets(arr[i].author, MAX_LEN_STR, f);
		fscanf(f, "%d", &(arr[i].seasons));
        fscanf(f, "%d", &(arr[i].rank));
        fgets(BUFF, SIZE_BUFF, f);
       
        numberOfAnime++;
    }
    deleteTheEnter(arr, numberOfAnime);
    return numberOfAnime;
}

void deleteTheEnter(anime* arr, int count) {
    for (int i = 0; i < count; i++) {
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';
        arr[i].author[strcspn(arr[i].author, "\n")] = '\0';
    }
}


void addTheAnimeToTheEndOfFile() {
    FILE* f = fopen("my_file.txt", "a");
    anime composition;
    anime* p = &composition;

    addParamsToStruct(p);

	fprintf(f, "%s\n%s\n%d\n%d\n", p->name, p->author, p->seasons, p->rank);

    fclose(f);
}



void addParamsToStruct(anime* p) {


    printf("Enter name of anime movie:\n");

    gets_s(p->name);

    printf("Enter author:\n");
    gets_s(p->author);

    printf("Enter seasons count:\n");
	scanf("%d", &(p->seasons));

    printf("Enter rank:\n");
    scanf("%d", &(p->rank));
}
