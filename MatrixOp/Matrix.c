#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
// #include <iostream>
// #include <cstdlib>

// using namespace std;

matrix2d *MakeMatrix(int t_rows, int t_cols)
{
    struct matrix2d *tempMat = (matrix2d *)malloc(sizeof(struct matrix2d));
    tempMat->row = t_rows;
    tempMat->column = t_cols;

    // tempMat->data = (double *)malloc(sizeof(double) * t_rows * t_cols);
    tempMat->data = (double *)calloc(t_rows * t_cols, sizeof(double));

    return tempMat;
}

// matrix2d* ScanMatrix(matrix2d m)
//{
// struct matrix2d* mat = malloc(sizeof(struct matrix2d));
// mat->row = R
// mat->column = C
//}
void PrintMatrix(matrix2d *m)
{
    int i, j;
    double t;
    for (i = 0; i < m->row; i++)
    {
        for (j = 0; j < m->column; j++)
        {
            t = m->data[i];
            printf("%d\t", m->data[i * j]);
        }
        printf("\n");
    }
}
matrix2d *MultiplyMatrix(matrix2d x, matrix2d y)
{
}
