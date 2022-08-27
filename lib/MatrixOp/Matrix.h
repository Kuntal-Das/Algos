#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#pragma once

typedef struct matrix2d
{
    char *name;
    int row;
    int column;
    double *data;
} matrix2d;

matrix2d *MakeMatrix(int t_rows, int t_cols, char* name);

void FreeMatrix(matrix2d *matrix2d);

void ScanMatrix(matrix2d *matrix);
void PrintMatrix(matrix2d *m);

matrix2d *MultiplyMatrix(matrix2d matA, matrix2d matB);
matrix2d *_StrassensMultiplyMatrix2x2(matrix2d matA, matrix2d matB);
matrix2d *_NativeMultiplyMatrix(matrix2d matA, matrix2d matB);

#endif // MATRIX_H_INCLUDED
