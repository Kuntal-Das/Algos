#include "Sorting.h"
#include "../Helpers/Helpers.h"


long Partition(double *arr, long startIndx, long endIndx)
{
    long pivotIndx = startIndx;
    long i = startIndx + 1, j = endIndx;
    while (i <= j)
    {
        while (arr[i] <= arr[pivotIndx] && i <= endIndx)
            i++;

        while (arr[j] > arr[pivotIndx] && j >= startIndx)
            j--;

        if (i < j)
            SwapDoubleByRef(&arr[i], &arr[j]);
    }
    if (j != pivotIndx)
        SwapDoubleByRef(&arr[j], &arr[pivotIndx]);

    return j;
}

/*
Time Complexity :
    Best  - O(n*log(n))
    Worst - O(n^2)
    Avg   - O(n*log(n))

Space Complesity: O(log(n))

Preserves Order : No
*/
void QuickSort(double *arr, long startIndx, long endIndx)
{
    if (startIndx < endIndx)
    {
        long pIndx = Partition(arr, startIndx, endIndx);
        QuickSort(arr, startIndx, pIndx - 1);
        QuickSort(arr, pIndx + 1, endIndx);
    }
}