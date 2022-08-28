#include "Sorting.h"
#include "../Array/Array.h"
#include "../Helpers/Helpers.h"

void SelectionSort(double *arr, long length)
{
    long i, maxIndx = 0;

    for (i = 0; i < length; i++)
    {
        maxIndx = GetIndexOfMinElement(arr, i, length - 1);
        if (maxIndx != i)
        {
            SwapDoubleByRef(&arr[i], &arr[maxIndx]);
        }
    }
}