#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct matrix2d
{
    int row;
    int column;
    double *data;
} matrix2d;

matrix2d *MakeMatrix(int t_rows, int t_cols);

void ScanMatrix(matrix2d *matrix, char *matName);

void PrintMatrix(matrix2d *m, char *matName);

#endif // MATRIX_H_INCLUDED
