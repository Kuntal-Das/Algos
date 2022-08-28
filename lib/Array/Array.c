#include <stdlib.h>
#include <stdio.h>
#include "Array.h"

double *MakeDblArray(long length)
{
    return (double *)malloc(length * sizeof(double));
}

void PrintDblArr(double *arr, long lenght)
{
    long i;
    for (i = 0; i < lenght; i++)
    {
        printf("%lf, ", arr[i]);
    }
    printf("\n");
}

void ScanDblArr(double *arr, long lenght)
{
    long i;
    printf("\n");
    for (i = 0; i < lenght; i++)
    {
        printf("Enter Element %d : ", i);
        scanf("%lf", &arr[i]);
    }
}

long GetIndexOfMaxElement(double *arr, long length)
{
    long i, maxIndx = 0;
    double max = arr[0];
    for (i = 1; i <= length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndx = i;
        }
    }
    return maxIndx;
}