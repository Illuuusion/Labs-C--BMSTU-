#include "stdafx.h"
#include "mystring.h"
unsigned strLength(const char* str){
	unsigned i;
	for (i = 0; str[i]; i++);
	return i;
}

char* strSearchOfSymbol(char* str, char symbol){
	char* p;
	for (p = str; *p && *p != symbol; p++);
	return *p ? p : 0;
}

int strDeleteSymbol(char* str, int index){
	unsigned i;
	for (i = index; i < strLength(str); i++){
		str[i] = str[i+1];
	}
	return 0;
}

char* symbolInString(char s, char* str){
	for(; *str&&*str!=s; str++);
    return *str == s ? str : 0;
}

char* strCopy(char* s1, const char* s2){
	for (unsigned i = 0; s1[i] = s2[i]; i++);
	return s1;
}

char* strDeleteString(char* s, unsigned n){
	if ( n > strLength(s))
		*s = 0;
	else
		strCopy(s, s+n);
	return s;
}

char* strpbrk(char* s, const char* sym){
	int i = 0;
	int j = 0;
	for (i = 0; s[i]; i++){
		for (j = 0; sym[j]; j++)
			if (s[i] == sym[j])
				return s+i;
	}
	return NULL;
}