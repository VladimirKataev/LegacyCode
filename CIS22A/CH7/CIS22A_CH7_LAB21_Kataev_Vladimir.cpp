/*
	Written by Vladimir Kataev
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	const int NUMDIVS = 3;
	const int NUMQRTS = 4;
	int sales[NUMDIVS][NUMQRTS];
	cout << fixed << setprecision(2);
	cout << "Enter Data:\n";
	int totalSales = 0;

	for(int a = 0; a < NUMDIVS; a++){
		cout << "Division #" << a+1 << endl;
		for(int b = 0; b < NUMQRTS; b++){
			cout << "Quarter " << b+1 << " sales:$";
			cin >> sales[a][b];
		}
		cout << endl;
	}

	for(int a=0; a < NUMDIVS; a++){
		for(int b = 0; b < NUMQRTS; b++)
			totalSales += sales[a][b];
	}

	cout << "Total sales were $"<< totalSales << endl;

	return 0;
}
/*
Enter Data:
Division #1
Quarter 1 sales:$1
Quarter 2 sales:$2
Quarter 3 sales:$3
Quarter 4 sales:$4

Division #2
Quarter 1 sales:$2
Quarter 2 sales:$3
Quarter 3 sales:$4
Quarter 4 sales:$5

Division #3
Quarter 1 sales:$3
Quarter 2 sales:$4
Quarter 3 sales:$5
Quarter 4 sales:$6

Total sales were $42
------------------------------
Enter Data:
Division #1
Quarter 1 sales:$43
Quarter 2 sales:$2
Quarter 3 sales:$45
Quarter 4 sales:$64

Division #2
Quarter 1 sales:$23
Quarter 2 sales:$54
Quarter 3 sales:$67
Quarter 4 sales:$8

Division #3
Quarter 1 sales:$1
Quarter 2 sales:$2
Quarter 3 sales:$3
Quarter 4 sales:$4

Total sales were $316

*/
