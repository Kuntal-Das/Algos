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
void BubbleSort(double *arr, long length)
{
    int i = 0, j = 0;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                SwapDoubleByRef(&arr[j], &arr[j + 1]);
                // arr[j] = arr[j] + arr[j + 1];
                // arr[j + 1] = arr[j] - arr[j + 1];
                // arr[j] = arr[j] - arr[j + 1];
            }
            // SwapDoubleByRef(&arr[j], &arr[j + 1]);
        }
    }
}