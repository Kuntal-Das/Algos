#include <stdio.h>
#include <stdlib.h>
#include "../lib/Multiplications/Multilplication.h"
#include "../lib/LcmGcd/LcmGcd.h"
#include "../lib/MatrixOp/Matrix.h"
#include "../lib/Helpers/Helpers.h"
#include "../lib/Sorting/Sorting.h"
#include "../lib/DS/Array/Array.h"
#include "../lib/Others/Others.h"

int main()
{
    int ch, ch2;
    freopen("../IO/stdin.txt", "r", stdin);
    freopen("../IO/stdout.txt", "w", stdout);

    while (1)
    {
        printf("\n1 for Integer Multiplication");
        printf("\n2 for GCD LCM");
        printf("\n3 for Matrix Multiplication");
        printf("\n4 for Sorting");
        printf("\n5 for Others");
        printf("\n0 for Exit");
        printf("\n Enter the correct choice:");
        scanf("%d", &ch);
        system("clear");

        switch (ch)
        {
        case 0:
            break;
        case 1:
        {
            printf("\n\n----------------Integer Multiplication--------------------\n\n");
            printf("\n1 for Larusa Multiplication");
            printf("\n1 for Karatsuba Multiplication");

            printf("\n Enter the correct choice:");
            scanf("%d", &ch2);

            switch (ch2)
            {
            case 1:
            {
                printf("\n\n----------------Larusa Multiplication--------------------\n\n");
                long *x = (long *)malloc(sizeof(long));
                long *y = (long *)malloc(sizeof(long));
                printf("\nEnter two positive integers: \n");
                scanf("%ld %ld", x, y);

                long *result1 = (long *)malloc(sizeof(long));
                long *result2 = (long *)malloc(sizeof(long));
                *result1 = LarusaMult(*x, *y);
                *result2 = LarusaMultRecursive(*x, *y);

                printf("\nThe Result is :\n");
                printf("\t LarusaMult(%ld, %ld) : %ld \n", *x, *y, *result1);
                printf("\t LarusaMultRecursive(%ld, %ld) : %ld \n", *x, *y, *result2);

                FreeMem(4, x, y, result1, result2);
                break;
            }
            case 2:
            {
                printf("\n\n---------------Karatsuba Multiplication---------------------\n\n");
                long long int *x = (long long int *)malloc(sizeof(long long int));
                printf("\nEnter the first integer: ");
                scanf("%lld", x);

                long long int *y = (long long int *)malloc(sizeof(long long int));
                printf("\nEnter the second integer: ");
                scanf("%lld", y);

                unsigned long long int *result = (unsigned long long int *)malloc(sizeof(unsigned long long int));
                *result = KaratsubaMult(*x, *y);
                printf("\n\t KaratsubaMult(%lld, %lld) : %llu \n", *x, *y, *result);

                FreeMem(3, x, y, result);
                break;
            }
            default:
                printf("Worng Choice!!!");
                break;
            }
            break;
        }
        case 2:
        {
            printf("\n\n----------------GCD LCM--------------------\n\n");
            printf("\n1 for GCD");
            printf("\n1 for LCM");

            printf("\n Enter the correct choice:");
            scanf("%d", &ch2);

            switch (ch2)
            {
            case 1:
                printf("\n\n---------------GCD---------------------\n\n");
                long *x = (long *)malloc(sizeof(long));
                long *y = (long *)malloc(sizeof(long));
                printf("\nEnter two integers: \n");
                scanf("%ld %ld", x, y);

                long *result1 = (long *)malloc(sizeof(long));
                long *result2 = (long *)malloc(sizeof(long));
                *result1 = Gcd(*x, *y);
                *result2 = GcdRecursive(*x, *y);

                printf("\nThe Result is :\n");
                printf("\t Gcd(%ld, %ld) : %ld \n", *x, *y, *result1);
                printf("\t GcdRecursive(%ld, %ld) : %d \n", *x, *y, *result2);

                FreeMem(4, x, y, result1, result2);
                break;
            case 2:
                printf("Implementaion doesn't exists");
                break;
            default:
                printf("Worng Choice!!!");
                break;
            }
            break;
        }
        case 3:
        {
            // printf("\n\n----------------Matrix--------------------\n\n");
            // printf("\n1 for GCD");
            // printf("\n1 for LCM");
            // scanf("%d", &ch2);

            printf("\n\n---------------Matrix Multiplication---------------------\n\n");
            long *row = (long *)malloc(sizeof(long));
            printf("Enter no of Row for First Matrix A: ");
            scanf("%d", row);

            long *col = (long *)malloc(sizeof(long));
            printf("Enter no of Row for First Matrix A: ");
            scanf("%d", col);
            if (*row <= 0 || *col <= 0)
            {
                printf("Entered Row(%d) and Column(%d) value is invalid\n", *row, *col);
                break;
            }
            matrix2d *matA = MakeMatrix(*row, *col, "A");

            printf("Enter no of Row for First Matrix B : ");
            scanf("%d", row);
            printf("Enter no of Row for First Matrix B : ");
            scanf("%d", col);
            if (*row <= 0 || *col <= 0)
            {
                printf("Entered Row(%d) and Column(%d) value is invalid\n", *row, *col);
                break;
            }
            matrix2d *matB = MakeMatrix(*row, *col, "B");

            ScanMatrix(matA);
            PrintMatrix(matA);

            ScanMatrix(matB);
            PrintMatrix(matB);

            matrix2d *result = MultiplyMatrix(*matA, *matB);

            PrintMatrix(result);

            FreeMem(5, row, col, matA, matB, result);
            break;
        }
        case 4:
        {
            printf("\n\n----------------Sorting--------------------\n\n");
            long *n = (long *)malloc(sizeof(long));
            printf("Enter the no of items to sort: ");
            scanf("%ld", n);

            double *arr = MakeDblArray(*n);
            ScanDblArr(arr, *n);
            printf("\nBefore Sorting:");
            PrintDblArr(arr, *n);

            printf("\n1 for Bubble Sort");
            printf("\n2 for Selection Sort");
            printf("\n3 for Insertion Sort");
            printf("\n4 for Quick Sort");
            printf("\n5 for Heap Sort");
            printf("\n6 for Merge Sort");

            printf("\n Enter the correct choice:");
            scanf("%d", &ch2);
            switch (ch2)
            {
            case 1:
                printf("\n\n---------------Bubble Sort---------------------\n\n");
                BubbleSort(arr, *n);
                break;
            case 2:
                printf("\n\n---------------Selection Sort---------------------\n\n");
                SelectionSortMin(arr, *n);
                break;
            case 3:
                printf("\n\n---------------Insertion Sort---------------------\n\n");
                InsertionSort(arr, *n);
                break;
            case 4:
                printf("\n\n---------------Quick Sort---------------------\n\n");
                QuickSort(arr, 0, *n - 1);
                break;
            default:
                printf("Worng Choice!!!");
                break;
            }

            printf("\nAfter Sorting:");
            PrintDblArr(arr, *n);

            FreeMem(2, n, arr);
            break;
        }
        case 5:
        {
            printf("\n\n----------------Others--------------------\n\n");
            printf("\n1 for Checking if a Number is Prime");
            printf("\n2 for nth Prime number");

            printf("\n Enter the correct choice:");
            scanf("%d", &ch2);

            switch (ch2)
            {
            case 1:
            {
                unsigned long long int *number = (unsigned long long int *)malloc(sizeof(unsigned long long int));
                printf("\nEnter a positive Integer: ");
                scanf("%lld", number);
                if (IsPrime(*number) == 1)
                    printf("\n%lld is Prime\n", *number);
                else
                    printf("\n%lld is not Prime\n", *number);
                break;
            }
            case 2:
            {
                long *n = (long *)malloc(sizeof(long));
                printf("\nEnter n: ");
                scanf("%ld", n);
                printf("%ldth Prime Number is: %lld\n", *n, GetnthPrime(*n));
                break;
            }
            default:
                printf("Worng Choice!!!");
                break;
            }
            break;
        }
        default:
            printf("Worng Choice!!!");
            break;
        }
        if (ch == 0)
        {
            printf("Exiting...\n");
            break;
        }
    }
    /*int size = 0;
    printf("Enter the max size: ");
    scanf("%d", &size);
    char* num1 = (char*)calloc(size, sizeof(char));
    char* num2 = (char*)calloc(size, sizeof(char));

    printf("\nEnter The first number: ");
    scanf("%s", num1);
    printf("\nEnter The second number: ");
    scanf("%s", num2);

    char* res = KaratsubaMultStr(num1, num2);

    printf("The Result is: %s", res);*/
}
