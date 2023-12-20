#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

#define SUCCESS 0
#define ERROR 1
#define SPACE_SYMBOL ' '
#define CORRECT_INPUT 2
#define SPACE_STRING " "

unsigned inputWidth();
void makeList(char* str, unsigned width, char** list);
char* strins(char* s, const char* subs);
void outputList(char** list, unsigned count);
char* replace(char* str, const char* oldSubstr, const char* newSubstr);
char* strdel(char* s, unsigned n);
void addSpace(char* str);

int main(){
	char* str = (char*)malloc(200*sizeof(char));
	gets(str);
	unsigned width = inputWidth();
	unsigned count = (strlen(str)/width)+1;
	char** list = (char**)malloc(count * sizeof(char*));
	makeList(str, width, list);
	outputList(list, count);
	getch();
	free(str);
	free(list);
	return 0;
}

unsigned inputWidth(){
  int n = 0;
  char d;
  printf("Enter width:\n");
  while (scanf("%u%c", &n, &d) != CORRECT_INPUT && d != '\n' && n < NULL){
    printf("Width must be integer type and positive\n");
    fflush(stdin);
  }
  return n;
}

void makeList(char* str, unsigned width, char** list){
	unsigned currentWidth = 0;
	unsigned currentcountOfSpace = 0;
	unsigned currentTotalWidth = 0;
	unsigned i = 0;
	char* p = str;
	char* pWord;
	while (currentTotalWidth <= width){
		for (char* pSpr; pSpr = strchr(p, SPACE_SYMBOL); p++){
			if (p != pSpr){
				currentWidth = strlen(p) - strlen(pSpr);
				currentcountOfSpace = 1;
				currentTotalWidth += currentWidth + currentcountOfSpace;
				p = pSpr;
				if (currentTotalWidth > width){
					currentTotalWidth -= currentWidth + currentcountOfSpace;
					break;
				}
				currentcountOfSpace = 0;
				currentWidth = 0;
			}
		}
		pWord = (char*)malloc((currentTotalWidth) * sizeof(char));
		pWord = strncpy(pWord, str, currentTotalWidth - 1);
		pWord[currentTotalWidth - 1] = '\0';
		char* newWord = (char*)malloc((width + 1) * sizeof(char));
		newWord[width] = '\0';
		unsigned count = 0;
		while (count < width){
			for (int i = 0; i < strlen(pWord); i++){
				if (pWord[i]){
					newWord[i] = pWord[i];
					count +=1;
					if (pWord[i] == ' '){
						addSpace(newWord+i);
						count+=1;
					}
				}
			}
		for(i; i < (strlen(str)/width)+1;){
			list[i] = (char*)malloc(width * sizeof(char));
			strcpy(list[i], newWord);
			str += currentTotalWidth;
			currentTotalWidth = 0;
		}
		i += 1;
		free(pWord);
	}
}
}
char* strins(char* s, const char* subs){
	char* stemp = (char*)malloc((strlen(s)+1) * sizeof(char));
	strcpy(stemp, s);
	strcpy(s, subs);
	strcat(s, stemp);
	free(stemp);
	return s;
}

void outputList(char** list, unsigned count){
	for(unsigned i = 0; i < count; i++){
		printf("%s", list[i]);
	}
}

char* replace(char* str, const char* oldSubstr, const char* newSubstr){
	char* p = str;
	while(p = strstr(str, oldSubstr)){
		strdel(p, strlen(oldSubstr));
		strins(p, newSubstr);
		p+=strlen(newSubstr);
		break;
	}
	return str;
}
char* strdel(char* s, unsigned n){
	if(n >= strlen(s))
		*s = 0;
	else
		strcpy(s, s+n);
	return s;
 }

void addSpace(char* str){
   for (int i = strlen(str); i >= 0; i--) {
       *(str + i + 1) = *(str + i);
   }
   *str = ' ';  
}