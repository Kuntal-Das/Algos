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

long GetIndexOfMaxElement(double *arr, long startIndx, long endIndx)
{
    long i, maxIndx = startIndx;
    double max = arr[0];
    for (i = startIndx + 1; i <= endIndx; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndx = i;
        }
    }
    return maxIndx;
}

long GetIndexOfMinElement(double *arr, long startIndx, long endIndx)
{
    long i, minIndx = startIndx;
    double min = arr[startIndx];
    for (i = startIndx + 1; i <= endIndx; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minIndx = i;
        }
    }
    return minIndx;
}
