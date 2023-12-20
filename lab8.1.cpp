#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include "mystring.h"

#define SUCCESS 0
#define ERROR 1
#define SpecialsSymbols "(),.!?-"

void deleteSpaces(char* str);

int main(){
	char str[] = "";
	gets(str);
	printf("|");
	printf(str);
	printf("|\n|");
	deleteSpaces(str);
	printf(str);
	printf("|");
	getch();
	return SUCCESS;
}

#if 0
void deleteSpaces(char* str){
	unsigned i, str_length;
	str_length = strLength(str);
	for (i = 0; i < str_length; i++){
		if (str[i] == ' '){
			if (i == 0 || symbolInString(str[i+1], SpecialsSymbols)){
				if (strDeleteSymbol(str, i) == SUCCESS){
					str_length--;
					i--;
				}
				continue;
			}
		}
	}
}
#endif

void deleteSpaces(char* str){
	unsigned count = 0;
	char* p = str;
	char* pSpr;
	char* p2;
	while (pSpr = strpbrk(p, " ")){
		p2 = pSpr;
		for (pSpr; *pSpr == ' '; pSpr++){
			count++;
		}
		if (p2 == str || strLength(p2) == count || symbolInString(*(p2+count), SpecialsSymbols)){
			strDeleteString(p2, count);
			p = pSpr;
			count = 0;
		}
		else{
			strDeleteString(p2, count-1);
			p = pSpr;
			count = 0;
		}
	}
}
