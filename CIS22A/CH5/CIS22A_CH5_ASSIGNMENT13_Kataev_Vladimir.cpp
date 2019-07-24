/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	int points = 0, books = 0;
	cout << "Enter books purchased:"; cin>>books;

	if(books == 1) points = 5;
	if(books == 2) points = 15;
	if(books == 3) points = 30;
	if(books >= 4) points = 60;
	cout << "You have " << points << " points\n";

	return 0;				
}	
/*
Enter books purchased:1
You have 5 points
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT13_Kataev_Vladimir.cpp && ./a.out
Enter books purchased:4
You have 60 points

*/
