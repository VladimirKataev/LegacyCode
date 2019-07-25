#include<stdio.h>
#include<stdlib.h>
void print(int rows, int cols, int* M);
int* transpose(int rows, int cols, int* M);
int main (int argc, char** argv){
	int mat[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	int rows = 3;
	int cols = 6;
	int *m ;
	print(rows,cols,mat);
	printf("\n");
	m = transpose(rows,cols,mat);
	//mat 	= *m;
	//Matrix = *mat;
	print(cols,rows,m);
	free(m);

}
int* transpose(int rows, int cols, int *M){
//	int tmp = rows;
//	rows = cols;
//	cols = tmp;
	int *N = malloc(sizeof(int)*rows*cols);
	
	int h = 0;
	int v = 0;
	for(int r = 0; r < rows; r++){
		for(int c = 0; c<cols; c++ ){
			N[c*rows+r] = M[r*cols+c];
		}
	}
	return N;
}
void print(int rows, int cols, int* M){
	for(int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
			printf("%3d", M[r* cols + c]);

		}
		printf("\n");
	}
}
