/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	double m = 0;
	cout << "Enter the mass:"; cin >> m;
	cout << "Object weighs " << m * 9.8<<endl;

	if(m > 1000/9.8)cout << "it's too heavy" << endl;
	if(m < 10/9.8)cout << "it's too light" << endl;
	return 0;				
}	
/*
Enter the mass:5
Object weighs 49
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT6_Kataev_Vladimir.cpp && ./a.out
Enter the mass:1
Object weighs 9.8
it's too light
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT6_Kataev_Vladimir.cpp && ./a.out
Enter the mass:9001
Object weighs 88209.8
it's too heavy

*/
