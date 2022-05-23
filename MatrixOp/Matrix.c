#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <iostream>
// #include <cstdlib>

// using namespace std;

matrix2d *MakeMatrix(int t_rows, int t_cols, char *name)
{
    int i, j;
    double *x;
    struct matrix2d *tempMat = (matrix2d *)malloc(sizeof(struct matrix2d));
    tempMat->row = t_rows;
    tempMat->column = t_cols;
    tempMat->name = name;

    // tempMat->data = (double *)malloc(sizeof(double) * t_rows * t_cols);

    // for (i = 0; i < t_rows; i++)
    //     for (j = 0; j < t_cols; j++)
    //     {
    //         tempMat->data[(i * tempMat->column) + j] = 0;
    //     }

    tempMat->data = (double *)calloc(t_rows * t_cols, sizeof(double));

    return tempMat;
}

void ScanMatrix(matrix2d *matrix)
{
    int i, j;
    printf("\n");
    for (i = 0; i < matrix->row; i++)
    {
        for (j = 0; j < matrix->column; j++)
        {
            printf("%s[%d, %d] : ", matrix->name, i, j);
            scanf("%lf", &matrix->data[(i * matrix->column) + j]);
        }
    }
}

void PrintMatrix(matrix2d *matrix)
{
    int i, j;
    // double t;
    printf("Matrix %s\n", matrix->name);
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

matrix2d *_NativeMultiplyMatrix(matrix2d matA, matrix2d matB)
{
    if (matA.column != matB.row)
        return NULL;
    int i, j, k;
    char *resultName = strcat(matA.name, matB.name);
    // sprintf(resultName, "(%s X %s)", matA.name, matB.name);
    matrix2d *matResult = MakeMatrix(matA.row, matB.column, resultName);

    for (i = 0; i < matA.row; i++)
    {
        for (j = 0; j < matB.column; j++)
        {
            for (k = 0; k < matB.row; k++)
            {
                matResult->data[i * matResult->column + j] += matA.data[i * matA.column + k] * matB.data[k * matB.column + j];
            }
        }
    }

    return matResult;
}
