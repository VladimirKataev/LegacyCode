/*
	Written by Vladimir Kataev
*/
#include<iostream>
using namespace std;

void show(int[], int);

int main(){
	const int LENGTH = 7;
	int test[] = {2,3,4,5,9,8,15};

	show(test, LENGTH);

	return 0;
}

void show(int disp[], int L){
	for(int a = 0; a < L; a++)
		cout << disp[a] << endl;
}
/*
2
3
4
5
9
8
15
*/
