#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
// #include <iostream>
// #include <cstdlib>

// using namespace std;

matrix2d *MakeMatrix(int t_rows, int t_cols)
{
    int i, j;
    double *x;
    struct matrix2d *tempMat = (matrix2d *)malloc(sizeof(struct matrix2d));
    tempMat->row = t_rows;
    tempMat->column = t_cols;

    tempMat->data = (double *)malloc(sizeof(double) * t_rows * t_cols);

    for (i = 0; i < t_rows; i++)
        for (j = 0; j < t_cols; j++)
        {
            // (tempMat->data + i * j) = -15;
            tempMat->data[(i * tempMat->column) + j] = 15;
            // *(x + i * j) = 15;
        }

    // tempMat->data = (double *)calloc(t_rows * t_cols, sizeof(double));

    return tempMat;
}

void ScanMatrix(matrix2d *matrix, char *matName)
{
    int i, j;
    for (i = 0; i < matrix->row; i++)
    {
        for (j = 0; j < matrix->column; j++)
        {
            printf("%s[%d, %d] : ", matName, i, j);
            scanf("%lf", &matrix->data[(i * matrix->column) + j]);
            printf("\n");
        }
    }
}

void PrintMatrix(matrix2d *matrix, char *matName)
{
    int i, j;
    // double t;
    printf("Matrix %s\n", matName);
    for (i = 0; i < matrix->row; i++)
    {
        printf("\t");
        for (j = 0; j < matrix->column; j++)
        {
            // t = m->data[i];
            printf("%lf\t", (matrix->data[(i * matrix->column) + j]));
        }
        printf("\n");
    }
}
// matrix2d *MultiplyMatrix(matrix2d x, matrix2d y)
// {
// }
