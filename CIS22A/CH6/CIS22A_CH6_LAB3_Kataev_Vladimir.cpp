/*
	Written by Vladimir Kataev
*/

#include<iostream>
using namespace std;

//Prototype functions
void displayValue(int);

int main(){
	cout << "Passing 5 to function\n";
	displayValue(5);
	cout << "Back to Main\n";
	return 0;
}


void displayValue(int a){
	cout << "I got me a " << a << endl;
}
/*

Passing 5 to function
I got me a 5
Back to Main

*/
