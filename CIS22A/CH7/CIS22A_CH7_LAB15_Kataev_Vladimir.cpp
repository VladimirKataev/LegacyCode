/*
	Written by Vladimir Kataev
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	const int NUM_EMPLOYEES = 5;
	int hours[NUM_EMPLOYEES];
	double payrate[NUM_EMPLOYEES];

	cout << "Enter the data of given employee:\n";
	cout << fixed << setprecision(2);
	for(int a = 0; a < NUM_EMPLOYEES; a++){
		cout << "Employee #" << a+1 << endl;
		cout << "Hours:";cin >> hours[a];
		cout << "Payrate:";cin >> payrate[a];
		cout << endl;
	}

	cout << "Gross pay is as follows:\n";
	for(int a = 0; a < NUM_EMPLOYEES; a++)
		cout << "#" << a+1 << ":$" << hours[a]*payrate[a] << endl;

	return 0;
}
/*
Enter the data of given employee:
Employee #1
Hours:2
Payrate:2

Employee #2
Hours:3
Payrate:3

Employee #3
Hours:4
Payrate:5

Employee #4
Hours:6
Payrate:7

Employee #5
Hours:25
Payrate:25

Gross pay is as follows:
#1:$4.00
#2:$9.00
#3:$20.00
#4:$42.00
#5:$625.00
------------------------------------------
Enter the data of given employee:
Employee #1
Hours:40
Payrate:15

Employee #2
Hours:60
Payrate:15

Employee #3
Hours:40
Payrate:30

Employee #4
Hours:20
Payrate:40

Employee #5
Hours:18
Payrate:100

Gross pay is as follows:
#1:$600.00
#2:$900.00
#3:$1200.00
#4:$800.00
#5:$1800.00

*/
