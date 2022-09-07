#include <stdlib.h>
#include "Sorting.h"
#include "../Helpers/Helpers.h"
#include "../DS/Array/Array.h"

void InPlaceMergeWithSelectionSort(double *arr, long start, long mid, long end)
{
    long i = start, j = mid + 1, k = 0;
    double temp;
    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            SwapDoubleByRef(&arr[i], &arr[j]);
            temp = arr[j];
            for (k = j + 1; k <= end; k++)
            {
                if (temp > arr[k])
                {
                    arr[k - 1] = arr[k];
                }
                else
                {
                    break;
                }
            }
            arr[k - 1] = temp;
        }
        i++;
    }
}
void Merge(double *arr, long start, long mid, long end)
{
    long i = start, j = mid + 1, k = start;
    double tempArr[end + 1 - start];
    // double *tempArr = MakeDblArray(end + 1 - start);

    tempArr[i - start] = arr[i];
    tempArr[j - start] = arr[j];

    while (i <= mid && j <= end)
    {
        if (tempArr[i - start] >= tempArr[j - start])
        {
            if (i < k + 1)
                tempArr[(k + 1) - start] = arr[k + 1];
            arr[k++] = arr[j++];
            if (j <= end)
                tempArr[j - start] = arr[j];
            else
                break;
        }
        else
        {
            arr[k++] = arr[i++];
            if (i <= mid && i >= k)
                tempArr[i - start] = arr[i];
            else
                break;
        }
    }
    while (i <= mid)
    {
        arr[k++] = tempArr[i - start];
        i++;
    }
    while (j <= end)
    {
        arr[k++] = tempArr[j - start];
        j++;
        if (j <= end)
            tempArr[j - start] = arr[j];
        else
            break;
    }
    // FreeMem(1, tempArr);
}

void MergeSort(double *arr, long startIndx, long endIndx)
{
    if (startIndx >= endIndx)
        return;

    long mid = (startIndx + endIndx) / 2;

    MergeSort(arr, startIndx, mid);
    MergeSort(arr, mid + 1, endIndx);
    // Merge(arr, startIndx, mid, endIndx);
    InPlaceMergeWithSelectionSort(arr, startIndx, mid, endIndx);
}