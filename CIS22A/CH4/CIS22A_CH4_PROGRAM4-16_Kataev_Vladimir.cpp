/*
	Program made by Vladimir Kataev
	Calculates overtime pay
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;
int main(){
        string companyName;
        cout << "Enter Company name:\n";
        getline(cin, companyName);
        unsigned int hours;
        cout << "Enter hours worked:\n";
        cin >> hours;
        unsigned double payRate;
        cout << "Enter hourly pay:\n";
        cin >> payRate;
        cout    << "Company:"<< companyName << endl;
	double netPay;
	if(hours > 40){
		netPay = (payRate*40) + (1.5 * payRate * (hours - 40));
	}
	else{
		netPay = payRate*40;
	}
	cout << "\nHours:"<<hours
                << "\nRate:"<<payRate;  //Intentional no \n, line continues with ID
        int id;
        srand(time(0));                 //semirandom seeding

        //          (max-min) + min
        id = (rand() % 1000) + 1000;

        cout    << "\nYour ID is:"<<id
                << "\nYour Gross Pay is:"<< netPay<< "\n";
        return 0;

}
/*
vladimir@VladTop:~/DeAnzaCPP$ ./a.out
Enter Company name:
Gewgl
Enter hours worked:
50
Enter hourly pay:
14.5
Company:Gewgl
Hours:50
Rate:14.5
Your ID is:1809
Your Gross Pay is:797.5
vladimir@VladTop:~/DeAnzaCPP$ ./a.out
Enter Company name:
doubleYeDoubleYeDoubleYeDotGEWGLDotCom
Enter hours worked:
30
Enter hourly pay:
14.5
Company:
doubleYeDoubleYeDoubleYeDotGEWGLDotCom
Hours:30
Rate:14.5
Your ID is:1593
Your Gross Pay is:580

*/
