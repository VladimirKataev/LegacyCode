/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	int al, aw, bl, bw;
	cout << "Enter the first rectangle's length:"; cin >> al;
	cout << "Breadth:"; cin >> aw;
	cout << "Second rectangle's length:"; cin >> bl;
	cout << "Breadth:"; cin >> bw;
	if(al*aw == bl*bw){
		cout << "They are of equal size\n";
		return 0;
	}
	(al*aw > bl*bw)?cout << "rectangle A bigger":cout << "Rectangle B bigger";
	return 0;				
}
/*
Enter the first rectangle's length:3
Breadth:4
Second rectangle's length:6
Breadth:2
They are of equal size
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT4_Kataev_Vladimir.cpp && ./a.out
Enter the first rectangle's length:5
Breadth:1
Second rectangle's length:2
Breadth:2
rectangle A bigger
*/
