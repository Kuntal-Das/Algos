#include "Sorting.h"
#include "../Array/Array.h"
#include "../Helpers/Helpers.h"

void SelectionSortMin(double *arr, long length)
{
    long i, minIndx = 0;

    for (i = 0; i < length; i++)
    {
        minIndx = GetIndexOfMinElement(arr, i, length - 1);
        if (minIndx != i)
        {
            SwapDoubleByRef(&arr[i], &arr[minIndx]);
        }
    }
}

void SelectionSortMax(double *arr, long length)
{
    long i, maxIndx = 0;

    for (i = length - 1; i >= 0; i--)
    {
        maxIndx = GetIndexOfMaxElement(arr, 0, i);
        if (maxIndx != i)
        {
            SwapDoubleByRef(&arr[i], &arr[maxIndx]);
        }
    }
}