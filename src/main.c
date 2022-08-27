#include <stdio.h>
#include <stdlib.h>
#include "../lib/Multilplications/Multiplication.h"
#include "../lib/LcmGcd/LcmGcd.h"
#include "../lib/MatrixOp/Matrix.h"
#include "../lib/Helpers/Helpers.h"
#include "../lib/Sorting/Sorting.h"
#include "../lib/Array/Array.h"

int main()
{
    int ch; // row, col;
    // long p, q, result1, result2;
    // long long int x, y;
    // unsigned long long int result;

    while (1)
    {
        printf("\n1 for Larusa Multiplication");
        printf("\n2 for Karatsuba Multiplication");
        printf("\n3 for Gcd");
        printf("\n4 for Matrix");
        printf("\n5 for BubbleSort");
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
            printf("\n\n---------------Karatsuba---------------------\n\n");
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
        case 3:
        {
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
        }
        case 4:
        {
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
        case 5:
        {
            printf("\n\n---------------Bubble Sort---------------------\n\n");
            int *n = (int *)malloc(sizeof(int));
            printf("Enter the no of items to sort: ");
            scanf("%d", n);

            double *arr = MakeDblArray(*n);
            ScanDblArr(arr, *n);
            printf("\nBefore Sorting:");
            PrintDblArr(arr, *n);

            BubbleSort(arr, *n);
            printf("\nAfter Sorting:");
            PrintDblArr(arr, *n);

            FreeMem(2, n, arr);
            break;
        }
        default:
            printf("Worng Choice!!!");
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
