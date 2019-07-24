/*
	Written by Vladimir Kataev
*/
#include<iostream>

int square(int);
double square(double);
using namespace std;
int main(){
	int userInt;
	double userDouble;

	cout << "Enter an int:"; cin >> userInt;
	cout << "Enter a double:"; cin >> userDouble;

	cout << "Int ^ 2 = " << square(userInt) << endl;
	cout << "Double ^ 2 = " << square(userDouble) << endl;

}

int square(int in){return in*in;}
double square(double in){return in*in;}
/*
Enter an int:5
Enter a double:2.714
Int ^ 2 = 25
Double ^ 2 = 7.3658

Enter an int:0
Enter a double:0
Int ^ 2 = 0
Double ^ 2 = 0

*/
