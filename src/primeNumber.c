#include <stdio.h>

void main()
{
    unsigned long long int n = 0, i = 0, j = 0, devideCount = 0, pCount = 0, temp = 0;
    unsigned long long int prime = 2;
    printf("Enter interger n: ");
    scanf("%lld", &n);

    for (i = 2, pCount = 1; pCount <= n + 1; i++)
    {
        devideCount = 0;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
                devideCount++;
        }

        if (devideCount == 0)
        {
            pCount++;

            if (pCount == n - 1 || pCount == n || pCount == n + 1)
                printf("%lldth Prime No : %lld\n", pCount - 1, i);
        }
        // else
        //     printf("%lld is not Prime Number\n\n", i);
    }

    // printf("\n%lldth Prime No is: %lld\n\n", n, prime);
}