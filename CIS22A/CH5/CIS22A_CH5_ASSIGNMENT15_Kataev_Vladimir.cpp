/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	double weight, distance, rate;
	do{
		cout << "Enter Weight:"; cin >>weight;
	}while(weight > 20 || weight < 0);
	do{
		cout << "Enter Distance:"; cin >>distance;
	}while (!(10 < distance && distance < 3000));
	if(weight < 2) rate = 1.1;
	else if(weight < 6) rate = 1.1*2;
	else if(weight < 10) rate = 3.7;
	else rate = 4.8;
	cout << "Charge: $" << (distance / 500)*rate <<endl;

	return 0;				
}	
/*
Enter Weight:-2
Enter Weight:2
Enter Distance:5
Enter Distance:5000
Enter Distance:500
Charge: $2.2


Enter Weight:3
Enter Distance:78
Charge: $0.3432

*/
