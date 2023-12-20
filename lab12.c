//#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
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
#define SORT_NAME 1
#define SORT_RANK 2

typedef struct{
    char name[MAX_LEN_STR];
    char author[MAX_LEN_STR];
    int seasons;
    int rank;
}Anime;

void outputMenu();
int inputCase(int* menuItem);
void warning();
void actionOfPerson(int menuItem, char* str);
void addTheAnimeToTheEndOfFile(char* str);
void outputAnimeOnScreen(char* str);
void addParamsToStruct(Anime* p);
void deleteByAuthor(char* str);
void deleteAnime(FILE* f, long currentPlace);
void sortAnime(char* str);
void sort(int(*compare)(Anime*, Anime*), char*str);
int compareByName(Anime* composition1, Anime* composition2);
int compareByRank(Anime* composition1, Anime* composition2);
char* enterNameFile();

int main() {
    char* str = enterNameFile();
    int menuItem;
    outputMenu();

    for (int key = inputCase(&menuItem); menuItem != EXIT; key = inputCase(&menuItem)) {
        if (!key) {
            warning();
        }
        else {

            actionOfPerson(menuItem, str);
        }

    }
    return 0;
}

char* enterNameFile() {
	char* str = (char*)malloc(MAX_LEN_STR * sizeof(char));
    printf("Enter name of file:\n");
	gets_s(str, MAX_LEN_STR);
    return str;
}


void outputMenu() {
    printf("Choose the action:\n");
    printf("1. Add the Anime at the end of file\n");
    printf("2. Display the Animes on the screen\n");
    printf("3. Sort Animes\n");
    printf("4. Delete the Anime\n");
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

void actionOfPerson(int menuItem, char* str) {
    switch (menuItem) {
	case ADD_ANIME: addTheAnimeToTheEndOfFile(str); break;
	case OUTPUT_ANIME_LIST: outputAnimeOnScreen(str); break;
	case SORT_ANIME: sortAnime(str); break;
	case DELETE_ANIME: deleteByAuthor(str); break;
    }
}

void sortAnime(char* str) {
    printf("You can choose:\n1.Sorting by name\n2.Sorting by rank\n");
    int figure;
	if (scanf("%d", &figure) == CORRECT_INPUT && (figure == SORT_NAME || figure == SORT_RANK)) {
		if (figure == SORT_NAME) {
            sort(compareByName, str);
        }
        else {
            sort(compareByRank, str);
        }
    }
    else {
        warning();
    }
}
void sort(int(*compare)(Anime*, Anime*), char* str) {
    FILE* f = fopen(str, "rb+");
    if (f == NULL) {
        warning();
    }
    else{
        fseek(f, 0, SEEK_END);
        int quantity = ftell(f) / sizeof(Anime);
        Anime compar;
        Anime place;
        fseek(f, 0, SEEK_SET);
        int numberOfRead = 0;
        while (fread(&place, sizeof(Anime), 1, f)) {
            if (!strcmp(place.name, "delete")) {
                numberOfRead++;
                fseek(f, numberOfRead * sizeof(Anime), SEEK_SET);
                continue;
            }
            int placeForRecording = numberOfRead;
            while (fread(&compar, sizeof(Anime), 1, f)) {
                if (!strcmp(compar.name, "delete")) {
                    placeForRecording++;
                    fseek(f, (placeForRecording + 1) * sizeof(Anime), SEEK_SET);
                    continue;
                }
                placeForRecording++;
                if (compare(&place, &compar) > 0) {
                    fseek(f, numberOfRead * sizeof(Anime), SEEK_SET);
                    fwrite(&compar, sizeof(Anime), 1, f);
                    fseek(f, placeForRecording * sizeof(Anime), SEEK_SET);
                    fwrite(&place, sizeof(Anime), 1, f);
                    fseek(f, (placeForRecording + 1) * sizeof(Anime), SEEK_SET);
                    place = compar;
                }
            }
            numberOfRead++;
            fseek(f, numberOfRead * sizeof(Anime), SEEK_SET);
        }
    }
    

}
int compareByName(Anime*composition1, Anime*composition2) {
    return strcmp(composition1->name , composition2->name);
}
int compareByRank(Anime* composition1, Anime* composition2) {
    return composition1->rank - composition2->rank;
}


void deleteByAuthor(char* str) {
    char selectAuthor[MAX_LEN_STR];

    printf("Enter the author:\n");
    gets_s(selectAuthor, MAX_LEN_STR);

    FILE* f = fopen(str, "rb+");
    if (f == NULL) {
        warning();
    }
    else{
        Anime composition;
        while (fread(&composition, sizeof(Anime), 1, f)) {
            if (!strcmp(composition.author, selectAuthor)) {
                long currentPlace = ftell(f) - sizeof(Anime);
                deleteAnime(f, currentPlace);
                fseek(f, currentPlace, SEEK_SET);
            }
        }
    }
}
void deleteAnime(FILE* f , long currentPlace) {

    fseek(f, currentPlace, SEEK_SET);
    Anime deleteComposition = { "delete", "delete", 0, 0};
    fwrite(&deleteComposition, sizeof(Anime), 1, f);
}


void addTheAnimeToTheEndOfFile(char* str) {
    FILE* f = fopen(str, "ab");
    if (f == NULL) {
        warning();
    }
    else{
        Anime composition;
        addParamsToStruct(&composition);
        fwrite(&composition, sizeof(Anime), 1, f);
        fclose(f);
    }
}

void addParamsToStruct(Anime* p) {


    printf("Enter name of Anime:\n");

    gets_s(p->name);

    printf("Enter author:\n");
    gets_s(p->author);

    printf("Enter seasons count:\n");
	scanf("%d", &(p->seasons));

    printf("Enter rank:\n");
    scanf("%d", &(p->rank));
}

void outputAnimeOnScreen(char* str) {
    FILE* f = fopen(str, "rb");
    if (f == NULL) {
        warning();
    }
    else{


        Anime composition;
        printf("-------------\n");

        while (fread(&composition, sizeof(Anime), 1, f)) {
            if (!strcmp(composition.name, "delete"))
                continue;
            printf("%s\n%s\n%d\n%d", composition.name, composition.author, composition.seasons, composition.rank);
			printf("\n-------------\n");

        }
        fclose(f);
    }
}
