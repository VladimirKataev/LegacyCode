/*
	Written By Vladimir Kataev

*/
#include<iostream>
using namespace std;


void displayMessage()
{
	cout << "This is within function\n";
}
int main(){
	cout << "This is within main\n";
	displayMessage();
	cout << "This is within main\n";
	return 0;
}
/*


This is within main
This is within function
This is within main


*/
