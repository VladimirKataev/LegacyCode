/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	double balance = 0;
	double fees = 10;
	int checks;
	cout << "Enter balance:"; cin >> balance;
	if(balance < 0){
		cout << "URGENT: ACCOUNT OVERDRAWN";
	}
	else{
		if(balance < 400)
			fees += 15;
		cout << "Enter checks written:"; cin >> checks;
		if(checks < 20) fees += (.1 * checks);
		else if(checks < 40) fees += (.08 * checks);
		else if(checks < 60) fees += (.06 * checks);
		else fees += (.04 * checks);
		cout << "Fees are $" << fees << endl;
	}

	return 0;				
}	
/*
Enter balance:-3
URGENT: ACCOUNT OVERDRAWN


Enter balance:500
Enter checks written:70
Fees are $12.8


*/
