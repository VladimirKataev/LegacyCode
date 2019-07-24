/*
	Written by Vladimir Kataev

*/
#include<iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

int getTotal(int[ROWS][COLS]);
int getAverage(int[ROWS][COLS]);
int getRowTotal(int[ROWS][COLS], int);
int getColumnTotal(int[ROWS][COLS], int);
int getHighestInRow(int[ROWS][COLS], int);
int getHighestInColumn(int[ROWS][COLS], int);


int main(){
	int data[ROWS][COLS] = {{2,3,6},
			{8,4,5},
			{9,0,4}};

	cout 	<< "Total:" << getTotal(data) << endl 
		<< "Average:" << getAverage(data) << endl
		<< "RowTotal(1)" << getRowTotal(data, 1) << endl
		<< "ColumnTotal(1)" << getColumnTotal(data, 1) << endl
		<< "RowHighest(1)" << getHighestInRow(data, 1) << endl
		<< "ColumnHighest(1)" << getHighestInColumn(data, 1) << endl;

	return 0;


}
int getTotal(int in[ROWS][COLS]){
	int t= 0;
	for(int a = 0; a < ROWS; a++){
		for(int b = 0; b < COLS; b++){
			t += in[a][b];
		}
	}
	return t;
}
int getAverage(int in[ROWS][COLS] ){
	return getTotal(in)/(ROWS*COLS);
}

int getRowTotal(int in[ROWS][COLS], int r){
	int t = 0;
	for(int a = 0; a < COLS; a++)
		t += in[r][a];
	return t;
}

int getColumnTotal(int in[ROWS][COLS], int c){
        int t = 0;
        for(int a = 0; a < ROWS; a++)
                t += in[a][c];
        return t;
}


int getHighestInRow(int in[ROWS][COLS], int r){
	int t = in[r][0];
	for(int a = 0; a < COLS; a++){
		if(in[r][a] > t)
			t = in[r][a];
	}
	return t;
}
int getHighestInColumn(int in[ROWS][COLS], int c){ 
        int t = in[0][c];
        for(int a = 0; a < ROWS; a++){ 
                if(in[a][c] > t)
                        t = in[a][c];
        }
        return t;
}

/*

Total:41
Average:4
RowTotal(1)17
ColumnTotal(1)7
RowHighest(1)8
ColumnHighest(1)4



*/
