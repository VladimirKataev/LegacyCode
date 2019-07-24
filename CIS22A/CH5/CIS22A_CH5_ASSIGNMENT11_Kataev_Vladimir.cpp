/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	int a, b, c;
	srand(time(NULL));
	a = (rand()%30)+1;
	b = (rand()%20)+1;

	cout << "Add " << a << "+" << b <<endl << "="; cin >> c;
	(c == a + b)?cout << "Correct\n":cout << "No, it's "<< a+b<<endl;
	return 0;				
}	
/*
Add 8+19
=20
No, it's 27
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT11_Kataev_Vladimir.cpp && ./a.out
Add 13+19
=32
Correct

*/
