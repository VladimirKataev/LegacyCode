/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	int month, day, year;
	cout << "Enter numerically day:";cin >> day;
	cout << "Enter numerically month:";cin >> month;
	cout << "Enter 2 digits of year:";cin >> year;
	(month*day == year)? cout << "Magic date\n":cout << "!magic date\n";
	return 0;				
}	
/*
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT3_Kataev_Vladimir.cpp && ./a.out
Enter numerically day:3
Enter numerically month:4
Enter 2 digits of year:05
!magic date
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT3_Kataev_Vladimir.cpp && ./a.out
Enter numerically day:3
Enter numerically month:4
Enter 2 digits of year:12
Magic date

*/
