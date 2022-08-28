#include <stdlib.h>
#include <time.h>
#include "Sorting.h"
#include "../Helpers/Helpers.h"

long PartitionWithStartIndexPivot(double *arr, long startIndx, long endIndx)
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

long PartitionWithRandomPivot(double *arr, long startIndx, long endIndx)
{
    srandom(time(NULL));
    long pivotIndx = startIndx + (random() % (endIndx - startIndx));
    long high = startIndx, low = endIndx;
    while (high <= low)
    {
        while (arr[high] <= arr[pivotIndx] && high <= endIndx)
        {
            high++;
            if (high == pivotIndx)
                high++;
        }

        while (arr[low] > arr[pivotIndx] && low >= startIndx)
        {
            low--;
            if (low == pivotIndx)
                low--;
        }

        if (high < low)
            SwapDoubleByRef(&arr[high], &arr[low]);
    }
    // if ((low < pivotIndx && high > pivotIndx))
    // {
    //     return pivotIndx;
    // }
    if (low < pivotIndx && high < pivotIndx && high <= endIndx)
    {
        SwapDoubleByRef(&arr[high], &arr[pivotIndx]);
        return high;
    }
    else if (low > pivotIndx && high > pivotIndx && low >= startIndx)
    {
        SwapDoubleByRef(&arr[low], &arr[pivotIndx]);
        return low;
    }
    return pivotIndx;
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
        // long pivotIndx = PartitionWithStartIndexPivot(arr, startIndx, endIndx);
        long pivotIndx = PartitionWithRandomPivot(arr, startIndx, endIndx);
        QuickSort(arr, startIndx, pivotIndx - 1);
        QuickSort(arr, pivotIndx + 1, endIndx);
    }
}