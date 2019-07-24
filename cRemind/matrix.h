#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef double MatrixValue;

typedef struct Matrix {
	int rows, cols;
	MatrixValue *data;
} Matrix;

void print(Matrix *M);
void freeMatrix(Matrix *M);
Matrix *transpose(Matrix *M);
Matrix *insert(Matrix *M, int ir, int ic, MatrixValue iv);
Matrix *Matrix_createID(int size) ;
void Matrix_transpose(Matrix *M) ;

#endif
