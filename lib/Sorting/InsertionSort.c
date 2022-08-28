#include "Sorting.h"
#include "../Helpers/Helpers.h"

/*
Time Complexity :
    Best  - O(n)
    Worst - O(n^2)
    Avg   - O(n^2)

Space Complesity: O(1)

Preserves Order : Yes
*/
void InsertionSort(double *arr, long length)
{
    long i, j;
    double key;
    for (i = 1; i < length; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = key;
    }
}