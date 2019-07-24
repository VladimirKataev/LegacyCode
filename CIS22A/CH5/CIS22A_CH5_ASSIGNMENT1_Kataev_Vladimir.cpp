/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	cout << "Enter 2 numbers:\nA:";
	int a,b;
	cin >> a;
	cout << "B:";
	cin >> b;
	(a > b)?cout << "A is bigger\n":cout << "B is bigger\n";
	return 0;				
}	
/*
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT1_Kataev_Vladimir.cpp && ./a.out
Enter 2 numbers:
A:5
B:6
B is bigger
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT1_Kataev_Vladimir.cpp && ./a.out
Enter 2 numbers:
A:6
B:4
A is bigger
*/
