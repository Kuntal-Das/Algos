#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct matrix2d
{
    int row;
    int column;
    double* data;
} matrix2d;


matrix2d* MakeMatrix(int t_rows, int t_cols);
//matrix2d* ScanMatrix(int** matrix);
void PrintMatrix(matrix2d* m);

#endif // MATRIX_H_INCLUDED
