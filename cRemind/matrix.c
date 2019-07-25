#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"

Matrix *insert(Matrix *M, int ir, int ic, MatrixValue iv){
	Matrix *N = malloc(sizeof(Matrix) + sizeof(MatrixValue)*(M->rows+1)*(M->cols + 1));
	MatrixValue *n = (MatrixValue*)(N+1);
	N->rows = M->rows+1;
	N->cols = M->cols+1;
	N->data = n;
	int vo, ho;
	for(int r = 0; r < M->rows; r++){
		for(int c = 0; c < M->cols; c++){
			ho = 0;vo = 0;
			if(r >=ir){vo++;}
			if(c >=ic){ho++;}
			N->data[(vo+r)*N->cols + c+ho] = M->data[r*M->cols+ c];
		}
	}
	N->data[ir*N->cols + ic] = iv;
	//freeMatrix(M);
	return N;
}


Matrix *transpose(Matrix *M)
{
	Matrix *n = malloc(sizeof(Matrix) + sizeof(MatrixValue)*M->rows*M->cols);
	MatrixValue *N = (MatrixValue*)(n+1);

	n->cols = M->rows;
	n->rows = M->cols;
	n->data = N;

	for(int r = 0; r < M->rows; r++){
		for(int c = 0; c < M->cols; c++ ){
			N[c*M->rows+r] = M->data[r*M->cols+c];
		}
	}

	return n;
}

void print(Matrix *M){
	for(int r = 0; r < M->rows; r++){
		for(int c = 0; c < M->cols; c++){
			printf("% 4d ", (int)M->data[r* M->cols + c]);

		}
		printf("\n");
	}
}


void freeMatrix(Matrix *M){
	free(M);
}
Matrix *Matrix_createID(int size) {
   Matrix *m = malloc(sizeof(Matrix)+sizeof(MatrixValue)*size*size);
	 m->rows = size; m->cols = size; m->data = (MatrixValue*)(m+1);
	 MatrixValue *dest = m->data;
	 *(dest++) = 1;
/*   for(int r = 0; r<size-1; r++) {
       for(int i = 0; i<size; i++)
           *(dest++) = 0;
       *(dest++) = 1;
   }*/
	 for(int rows = 1; rows < size; rows++){
	 	for(int blanks = 0; blanks < size; blanks++){
		 	*(dest++) = 0;
	 	}
		*(dest++) = 1;
	}
  return m;
}
void Matrix_transpose(Matrix *M){
	MatrixValue *dest = M->data;	//pointer to where we swap to
	MatrixValue *orig = M->data;	//pointer to where we swap from
	MatrixValue *rowC = M->data;	//pointer to start of newer segment
	MatrixValue *destR = M->data;	//pointer to start of segment of switching
	MatrixValue *ref = M->data;		//pointer of VERY start
	int r = M->rows; int vo = 0;
	int c = M->cols; int h = 0;
	int t = r*c;
	MatrixValue tmp;
	printf("%lf %d\n", *rowC, c);
	int tpm;
	for(int i = 0; i < c && i < r; i++){
		//dest = ref;
		//dest += i;
		destR =ref+ i;
		dest = destR;
		for(int j = 1+i; j < c && j < r; j++){
			//printf("\n[J:%d]\n", j);
			printf("Working with rowC of %d\n", rowC - ref);
			orig = rowC + j;
			dest += c;
			//printf("[origin:%2d,Dest:%2d]",(int) *orig,(int) *dest);
			printf("Swapping %d %d\n",orig -ref,dest -ref);
			tmp = *orig;
			*orig = *dest;
			*dest = tmp;

			//printf("\nSwapped %4d with %4d\n",(int)*dest, (int)*orig );

		}
		rowC += c;
		//printf("\n[rowC: %4d,i:%2d]\n", rowC - ref,i);
//		*orig = *rowC;
//		dest +=  i;
	}
/*
	tpm = M->rows;
	M->rows = M->cols;
	M->cols = tpm; */
}
void MatrixSquareEfficientTranspose(Matrix *m){
	MatrixValue *First = m->data;
	MatrixValue *Second = m->data;
	MatrixValue *SecondCol = m->data;
	MatrixValue *SecondRowStart = m->data;
	MatrixValue *FirstRow = m->data;
	MatrixValue *ref = m->data;
	MatrixValue tmp;
	MatrixValue *SecondBase = m->data;
	int dim = m->rows;
	SecondBase -= 1;
	for(int i = 0; i < dim-1; i++){
		SecondBase += dim + 1;

		Second = SecondBase;
		for(int j = i+1; j < dim; j++){
			First = FirstRow + j;
			tmp = *First;
			*First = *Second;
			*Second = tmp;
			//printf("\n Swapped %4d and %4d", *First, *Second);
			Second += dim;

		}
		FirstRow += dim;
	}

}
void MatrixEfficientTranspose(Matrix *m){
	MatrixValue *First = m->data;
	MatrixValue *Second = m->data;
	MatrixValue *SecondCol = m->data;
	MatrixValue *SecondRowStart = m->data;
	MatrixValue *FirstRow = m->data;
	MatrixValue *ref = m->data;
	MatrixValue tmp;
	MatrixValue *SecondBase = m->data;
	int dim = m->rows;
	int cols = m->cols;
	SecondBase -= 1;
	for(int i = 0; i < dim-1 && i < cols; i++){
		SecondBase += cols + 1;

		Second = SecondBase;
		for(int j = i+1; j < dim && j < cols; j++){
			First = FirstRow + j;
			tmp = *First;
			*First = *Second;
			*Second = tmp;
			//printf("\n Swapped %4d and %4d", *First, *Second);
			Second += cols;

		}
		FirstRow += cols;
	}/*
	m->rows = cols;
	m->cols = dim;*/
}
