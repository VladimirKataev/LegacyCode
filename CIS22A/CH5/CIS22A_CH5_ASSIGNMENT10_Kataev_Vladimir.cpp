/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	int m, y;
	do{
		cout << "Enter a month(1-12):"; cin >> m;
	}while(!(1 <= m && m <= 12));
	cout << "Enter a year:"; cin >> y;
	switch(m){
		case 1: 
			cout << "31 days\n";
			break;
		case 2:
			(y % 4 == 0)?cout << "29 days\n": cout << "28 days\n";
			break;
		case 3:
			cout << "31 days\n";
			break;
		case 4:
			cout << "30 days\n";
			break;
		case 5:
			cout << "31 days\n";
			break;
		case 6:
			cout << "30 days\n";
			break;
		case 7:
			cout << "31 days\n";
			break;
		case 8: 
			cout << "31 days\n";
			break;
		case 9: 
			cout << "30 days\n";
			break;
		case 10: 
			cout << "31 days\n";
			break;
		case 11:
			cout << "30 days\n";
			break;
		case 12:
			cout << "31 days\n";
			break;
	}
	return 0;				
}	
/*
Enter a month(1-12):2
Enter a year:2000
29 days
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT10_Kataev_Vladimir.cpp && ./a.out
Enter a month(1-12):4
Enter a year:32
30 days

*/
