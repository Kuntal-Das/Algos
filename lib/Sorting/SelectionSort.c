#include "Sorting.h"
#include "../Array/Array.h"
#include "../Helpers/Helpers.h"

/*
Time Complexity :
    Best  - O(n^2)
    Worst - O(n^2)
    Avg   - O(n^2)

Space Complesity: O(1)

Preserves Order : No
*/
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

/*
Time Complexity :
    Best  - O(n^2)
    Worst - O(n^2)
    Avg   - O(n^2)

Space Complesity: O(1)

Preserves Order : No
*/
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