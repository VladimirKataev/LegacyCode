/*
	Written By Vladimir Kataev
*/
#include<iostream>
using namespace std;

void first();
void second();


int main(){
	cout << "I'm in main function\n";
	first();
	second();

	cout << "I'm in main function\n";
	return 0;
}



void first(){cout << "First Function\n";}
void second(){cout << "Second Function\n";}



/*

I'm in main function
First Function
Second Function
I'm in main function

*/
