#include "Sorting.h"
#include "../Array/Array.h"
#include "../Helpers/Helpers.h"

void SelectionSort(double *arr, long length)
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