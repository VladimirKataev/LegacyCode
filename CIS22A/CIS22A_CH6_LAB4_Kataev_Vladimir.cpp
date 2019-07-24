/*
	Written by Vladimir Kataev
*/
#include<iostream>
#include<iomanip>
using namespace std;

void showIntro();
double getCups();
double cupsToOunces(double);


int main(){
	//malloc
	double cups, ounces;
	//setup
	cout << fixed << showpoint << setprecision(1);


	//ok let's go
	showIntro();

	ounces =cupsToOunces(getCups());

	cout << "That converts to " << ounces << " Ounces\n";


	return 0;
}

void showIntro(){
	cout << "This converts a number of cups to ounces\n";
}
double getCups(){
	double tmp;
	cout << "Enter the Number of Cups:"; cin >> tmp;
	return tmp; //don't create memory leaks
}
double cupsToOunces(double cups){
	return cups*8.0;
}


/*

This converts a number of cups to ounces
Enter the Number of Cups:5
That converts to 40.0 Ounces

This converts a number of cups to ounces
Enter the Number of Cups:3.5
That converts to 28.0 Ounces


*/
