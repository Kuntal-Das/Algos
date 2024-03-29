#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

#pragma once
#include <stddef.h>
#define MAX(X, Y) ((X > Y) ? X : Y)

char *strrev(char *str);

int Length(long num);

void Swap(void *arg1, void *arg2, size_t len);

void SwapLongByRef(long *arg1, long *arg2);
void SwapDoubleByRef(double *arg1, double *arg2);
void SwapStrByRef(char **arg1, char **arg2);

char *FindSum(char *str1, char *str2);

char *ToStr(long num);
char *SubString(char *str, int startIndex, int endIndex);
char *AddRight(char *str, char ch, int num);
char *AddLeft(char *str, char ch, int num);
char *ConcatStr(int n_args, ...);
int isStrsEqual(char *str1, char *str2);

void FreeMem(int n_args, ...);

#endif // HELPERS_H_INCLUDED
