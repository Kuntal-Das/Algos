#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

#define MAX(X, Y) ((X > Y)? X : Y)

int Length(long num);
void swap(char** str1, char** str2);
char* findSum(char* str1, char* str2);
char* ToStr(long num);
char* SubString(char* str, int startIndex, int endIndex);
char* AddRight(char* str, char ch, int num);
char* AddLeft(char* str, char ch, int num);

#endif // HELPERS_H_INCLUDED
