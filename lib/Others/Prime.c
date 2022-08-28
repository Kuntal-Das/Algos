int IsPrime(unsigned long long int number)
{
    int devideCount = 0;
    unsigned long long int j;
    for (j = 2; j <= number / 2; j++)
    {
        if (number % j == 0)
        {
            devideCount++;
            break;
        }
    }

    if (devideCount == 0)
        return 1;

    return -1;
}

unsigned long long int GetnthPrime(long n)
{
    long pCount;
    unsigned long long int i;
    for (i = 2, pCount = 1; pCount <= n + 1; i++)
    {
        if (IsPrime(i) == 1)
            pCount++;
        
        if (pCount == n)
            return i;
    }
}