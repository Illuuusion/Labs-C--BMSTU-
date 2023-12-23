#ifndef _mystring_
#define _mystring_
unsigned strLength(const char* str);
char* strSearchOfSymbol(char* str, char symbol);
int strDeleteSymbol(char* str, int index);
char* symbolInString(char s, char* str);
char* strDeleteString(char* s, unsigned n);
char* strCopy(char* s1, const char* s2);
char* strpbrk(char* s, const char* sym);
#endif