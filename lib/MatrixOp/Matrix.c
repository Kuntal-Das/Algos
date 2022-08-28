#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Matrix.h"
#include "../Helpers/Helpers.h"

// using namespace std;

matrix2d *MakeMatrix(int t_rows, int t_cols, char *name)
{
    int i, j;
    double *x;
    struct matrix2d *tempMat = (matrix2d *)malloc(sizeof(struct matrix2d));
    tempMat->row = t_rows;
    tempMat->column = t_cols;
    tempMat->name = name;

    tempMat->data = (double *)calloc(t_rows * t_cols, sizeof(double));

    return tempMat;
}

void FreeMatrix(matrix2d *matrix2d)
{
    free(matrix2d->data);
    free(matrix2d->name);
    free(matrix2d);
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

matrix2d *MultiplyMatrix(matrix2d matA, matrix2d matB)
{
    if (matA.column != 2 || matA.row != 2 || matB.column != 2 || matB.row != 2)
        return _NativeMultiplyMatrix(matA, matB);

    return _StrassensMultiplyMatrix2x2(matA, matB);
}

matrix2d *_NativeMultiplyMatrix(matrix2d matA, matrix2d matB)
{
    if (matA.column != matB.row)
        return NULL;
    int i, j, k;
    char *resultName = ConcatStr(4, "( ", matA.name, matB.name, " )");
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

matrix2d *_StrassensMultiplyMatrix2x2(matrix2d matA, matrix2d matB)
{
    if (matA.column != 2 || matA.row != 2 || matB.column != 2 || matB.row != 2)
        return _NativeMultiplyMatrix(matA, matB);

    double m1, m2, m3, m4, m5, m6, m7;
    char *resultName = ConcatStr(4, "( ", matA.name, matB.name, " )");
    matrix2d *matResult = MakeMatrix(2, 2, resultName);

    m1 = (matA.data[0] + matA.data[3]) * (matB.data[0] + matB.data[3]);
    m2 = (matA.data[2] + matA.data[3]) * matB.data[0];
    m3 = matA.data[0] * (matB.data[1] - matB.data[3]);
    m4 = matA.data[3] * (matB.data[2] - matB.data[0]);
    m5 = (matA.data[0] + matA.data[1]) * matB.data[3];
    m6 = (matA.data[2] - matA.data[0]) * (matB.data[0] + matB.data[1]);
    m7 = (matA.data[1] - matA.data[3]) * (matB.data[2] + matB.data[3]);

    matResult->data[0] = m1 + m4 - m5 + m7;
    matResult->data[1] = m3 + m5;
    matResult->data[2] = m2 + m4;
    matResult->data[3] = m1 - m2 + m3 + m6;

    return matResult;
}
