/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	int dimes, pennies, nickels, quarters;
	cout << "Enter # of pennies:"; cin >> pennies;
	cout << "Enter # of nickels:"; cin >> nickels;
	cout << "Enter # of dimes:"; cin >> dimes;
	cout << "Enter # of quarters:"; cin >> quarters;

	int total = (pennies)+(nickels * 5)+(dimes * 10)+(quarters*25);
	if(total == 100)
		cout << "Correct\n";
	else
		(total > 100)?cout << "Too large\n": cout << "Too small\n";
	return 0;				
}	
/*
Enter # of pennies:100
Enter # of nickels:0
Enter # of dimes:0
Enter # of quarters:0
Correct
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT9_Kataev_Vladimir.cpp && ./a.out
Enter # of pennies:230
Enter # of nickels:30
Enter # of dimes:2
Enter # of quarters:1
Too large

*/
