#include "matrix.h"
#include "matrix.h"

int main(int argc, char** argv){
	MatrixValue mat[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	Matrix mtx = {4, 4, mat};
	//print(&mtx);
	MatrixValue mat2[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	Matrix mtx2 = {3, 6, mat};
	print(&mtx2);
	MatrixEfficientTranspose(&mtx2);
	printf("\n" );
	print(&mtx2);
//	printf("\n");
	//m = transpose(&mtx);
	//print(m);
	//Matrix *n = Matrix_createID(3);
	//Matrix *n =

	//print(&m);
//	print(insert(m, 2, 2, 88.8));

	//freeMatrix(m);
	//freeMatrix(n);


}
