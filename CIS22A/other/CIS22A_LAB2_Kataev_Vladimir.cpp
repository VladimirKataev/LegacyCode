/*
	Written By Vladimir Kataev
	Calculates gross pay, and assigns ID
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
int main(){
	string companyName;
	cout << "Enter Company name:\n";
	getline(cin, companyName);
	int hours;
	cout << "Enter hours worked:\n";
	cin >> hours;
	double payRate;
	cout << "Enter hourly pay:\n";
	cin >> payRate;
	cout 	<< "Company:"<< companyName
		<< "\nHours:"<<hours
		<< "\nRate:"<<payRate;	//Intentional no \n, line continues with ID
	int id;
	srand(time(0));			//semirandom seeding

	//	    (max-min) + min
	id = (rand() % 1000) + 1000;

	cout 	<< "\nYour ID is:"<<id
		<< "\nYour Gross Pay is:"<< hours * payRate << "\n";
	return 0;
}
/*
Enter Company name:
De Anza
Enter hours worked:
34
Enter hourly pay:
66
Company:De Anza
Hours:34
Rate:66
Your ID is:1290
Your Gross Pay is:2244


Enter hourly pay:
66
Company:De Anza
Hours:34
Rate:66
Your ID is:1063
Your Gross Pay is:2244

*/
