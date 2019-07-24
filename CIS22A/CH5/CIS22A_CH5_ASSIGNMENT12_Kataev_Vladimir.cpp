/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
#include<iomanip>
using namespace std;			
int main(){				
	int order = 0; double total;
	do{
		cout << "Enter your order quantity:"; cin >> order;
	}while(order <= 0);
	std::cout << setprecision(2) << fixed;
	double discount = 0;
	if(order >= 100) discount = .5;
	else if(order >= 100) discount = .5;
	else if(order >= 50) discount = .4;
	else if(order >= 20) discount = .3;
	else if(order >= 10) discount = .2;
	cout << "Your total comes to $" << 99*order * (1-discount) << endl;
	return 0;
}
/*
Enter your order quantity:-2
Enter your order quantity:2
Your total comes to $198.00
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT12_Kataev_Vladimir.cpp && ./a.out
Enter your order quantity:70
Your total comes to $4158.00

*/
