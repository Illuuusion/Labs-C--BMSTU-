#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

#define SUCCESS 0
#define ERROR 1
#define SPECIALS_SYMBOLS "(),.!?- "
#define MAX_SIZE 100

typedef struct Word {
	char* word;
	unsigned count;
}word_t;

unsigned parseWords(word_t* dictionary, char* str);
void strToLower(char* str);
unsigned countWords(char* str, const char* spr);
void swapElement(word_t* adress1, word_t* adress2);
unsigned makeFrequencyDictionary(word_t* dictionary, unsigned count);
void sortDictionary(word_t* dictionary, unsigned count, int(*compare)(word_t*, word_t*));
void outputDictionary(word_t* dictionary, unsigned count);
void freeDictionaryMemory(word_t* dictionary, unsigned count);
void deleteElementOfDictionary(word_t* dictionary, unsigned count, unsigned index);
unsigned makeDictionary(word_t* dictionary, char* str, unsigned count);
char* strAllocateMemory();
int compareCount(word_t* s1, word_t* s2);

int main() {
	char* str = strAllocateMemory();
	strToLower(str);
	unsigned count = countWords(str, SPECIALS_SYMBOLS);
	word_t* dictionary = (word_t*)malloc(sizeof(word_t) * count);
	count = makeDictionary(dictionary, str, count);
	outputDictionary(dictionary, count);
	freeDictionaryMemory(dictionary, count);
	_getch();
	return 0;
}

unsigned parseWords(word_t* dictionary, char* str) {
	unsigned i = 0;
	char* p = str;
	for (char* pSpr; pSpr = strpbrk(p, SPECIALS_SYMBOLS); p++) {
		if (p != pSpr) {
			long len = strlen(p) - strlen(pSpr);
			dictionary[i].word = (char*)malloc((len + 1) * sizeof(char));
			strncpy(dictionary[i].word, p, len + 1);
			dictionary[i].word[len] = '\0';
			dictionary[i].count = 1;
			i++;
			p = pSpr;
		}
	}
	if (strlen(p)) {
		dictionary[i].word = (char*)malloc((strlen(p)) * sizeof(char));
		strcpy(dictionary[i].word, p);
		dictionary[i].count = 1;
	}
	return i + 1;
}

void strToLower(char* str) {
	for (unsigned i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
}

unsigned countWords(char* str, const char* spr) {
	unsigned count = 0;
	char* p = str;
	char* pSpr;
	while (pSpr = strpbrk(p, spr)) {
		if (p != pSpr) {
			p = pSpr + 1;
			count++;
		}
		else
			p++;
	}
	if (strlen(p))
		count++;
	return count;
}

void swapElement(word_t* adress1, word_t* adress2) {
	word_t save = *adress1;
	*adress1 = *adress2;
	*adress2 = save;
}

unsigned makeFrequencyDictionary(word_t* dictionary, unsigned count) {
	unsigned shift = 0;
	unsigned count1 = count;
	for (unsigned i = 0; i < count - shift; i++) {
		for (unsigned j = i + 1; j < count1; j++) {
			if (strcmp(dictionary[i].word, dictionary[j].word) == NULL) {
				dictionary[i].count += 1;
				deleteElementOfDictionary(dictionary, count - shift, j);
				shift += 1;
			}
		}
		if (count1 > shift) {
			count1 -= shift;
		}
	}
	return count - shift;
}

void sortDictionary(word_t* dictionary, unsigned count, int(*compare)(word_t*, word_t*)) {
	for (unsigned i = 0; i < count; i++) {
		for (unsigned j = i + 1; j < count; j++) {
			if (compare(dictionary + i, dictionary + j) < 0) {
				swapElement(dictionary + i, dictionary + j);
			}
		}
	}
}
void outputDictionary(word_t* dictionary, unsigned count) {
	for (unsigned i = 0; i < count; i++) {
		printf("%s: %u\n", dictionary[i].word, dictionary[i].count);
	}
}

void freeDictionaryMemory(word_t* dictionary, unsigned count) {
	for (unsigned i = 0; i < count - 1; i++) {
		free(dictionary[i].word);
	}
	free(dictionary);
}
void deleteElementOfDictionary(word_t* dictionary, unsigned count, unsigned index) {
	for (unsigned i = index; i < count; i++) {
		dictionary[i] = dictionary[i + 1];
	}
}

unsigned makeDictionary(word_t* dictionary, char* str, unsigned count) {
	count = parseWords(dictionary, str);
	count = makeFrequencyDictionary(dictionary, count);
	sortDictionary(dictionary, count, compareCount);
	return count;
}

int compareCount(word_t* s1, word_t* s2) {
	return s1->count - s2->count;
}

#if 0
char* strAllocateMemory() {
	int size = MAX_SIZE;
	int memorySize = MAX_SIZE;
	char* str = (char*)malloc(size * sizeof(char));
	char buf[MAX_SIZE];
	while(fgets(buf, MAX_SIZE, stdin)){
		if (MAX_SIZE + size > memorySize) {
			memorySize *= 2;
			str = (char*)realloc(str, memorySize * sizeof(char));
		}
		strcat(str, buf);
		size += strlen(buf);
	}
	return str;
}
#endif

char* strAllocateMemory(){
	char* str = (char*)malloc(MAX_SIZE * sizeof(char));
	gets(str);
	return str;
}
