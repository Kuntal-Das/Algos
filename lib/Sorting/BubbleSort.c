void BubbleSort(double *arr, int length)
{
    int i = 0, j = 0;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
            // SwapDoubleByRef(&arr[j], &arr[j + 1]);
        }
    }
}