#include <stdlib.h>
#include <stdio.h>

double *MakeDblArray(int length)
{
    return (double *)malloc(length * sizeof(double));
}

void PrintDblArr(double *arr, int lenght)
{
    int i;
    for (i = 0; i < lenght; i++)
    {
        printf("%lf, ", arr[i]);
    }
    printf("\n");
}

void ScanDblArr(double *arr, int lenght)
{
    int i;
    printf("\n");
    for (i = 0; i < lenght; i++)
    {
        printf("Enter Element %d : ", i);
        scanf("%lf", &arr[i]);
    }
}