#include <stdio.h>
#include <stdlib.h>
#include "Multilplications/Multiplication.h"
#include "LcmGcd/LcmGcd.h"
#include "MatrixOp/Matrix.h"

int main()
{
    int ch;
    long p, q, result1, result2;
    long long int x, y;
    unsigned long long int result;

    while (1)
    {
        printf("\n1 for Larusa Multiplication");
        printf("\n2 for Karatsuba Multiplication");
        printf("\n3 for Gcd");
        printf("\n4 for Matrix");
        printf("\n0 for Exit");
        printf("\n Enter the correct choice:");
        scanf("%d", &ch);
        system("cls");

        switch (ch)
        {
        case 0:
            break;
        case 1:
        {
            printf("\n\n----------------Larusa Multiplication--------------------\n\n");
            printf("\nEnter two positive integers: \n");
            scanf("%ld %ld", &p, &q);

            result1 = LarusaMult(p, q);
            result2 = LarusaMultRecursive(p, q);

            printf("\nThe Result is :\n");
            printf("\t LarusaMult(%ld, %ld) : %ld \n", p, q, result1);
            printf("\t LarusaMultRecursive(%ld, %ld) : %ld \n", p, q, result2);
            break;
        }
        case 2:
        {
            printf("\n\n---------------Karatsuba---------------------\n\n");
            printf("\nEnter the first integer: ");
            scanf("%lld", &x);
            printf("\nEnter the second integer: ");
            scanf("%lld", &y);
            result = KaratsubaMult(x, y);
            printf("\n\t KaratsubaMult(%lld, %lld) : %llu \n", x, y, result);
            break;
        }
        case 3:
        {
            printf("\n\n---------------GCD---------------------\n\n");
            printf("\nEnter two integers: \n");
            scanf("%ld %ld", &p, &q);

            result1 = Gcd(p, q);
            result2 = GcdRecursive(p, q);

            printf("\nThe Result is :\n");
            printf("\t Gcd(%ld, %ld) : %ld \n", p, q, result1);
            printf("\t GcdRecursive(%ld, %ld) : %d \n", p, q, result2);
            break;
        }
        case 4:
        {
            printf("\n\n---------------Matrix Multiplication---------------------\n\n");
            matrix2d *A = MakeMatrix(3, 3);
            matrix2d *B = MakeMatrix(3, 3);
            PrintMatrix(A);
            break;
        }
        default:
            printf("Worng Choice!!!");
        }
        if (ch == 0)
            break;
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
