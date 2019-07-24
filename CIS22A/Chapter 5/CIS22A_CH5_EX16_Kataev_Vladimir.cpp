/*Written By Vladimir Kataev*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

double getPosDoubleResponse(string);

int main(){
	int months = getPosDoubleResponse("How many months ago was your account established");
	double interest = getPosDoubleResponse("What is the interest rate of your account");
	interest /= 100; interest += 1; //To be used in actual maths, turning 17% interest to 1.17
	double balance = getPosDoubleResponse("What was the starting balance");
	double in, out;


	for(int a = 0; a < months; a++){
		cout << "--------- Month " << a << endl;
		in = getPosDoubleResponse("What deposits did you make");
		out = getPosDoubleResponse("What withdrawals did you make");
		balance += in - out;
		if(balance < 0){
			cout << "Out of money, account closed\n";
			return 0;
		}
		balance *= ((interest - 1)/12)+1;
		cout << "Your balance is " << balance<<endl;
	}



}


double getPosDoubleResponse(string prompt){ // As function prints end after cin, no \n needed
	double response = 0;
	do{
		if(response < 0)
			cout << "Enter a Positive Number\n";
		cout << prompt << ":";
		cin >> response;
	}while(response < 0);
	return response;
}
/*
How many months ago was your account established:-2.5
Enter a Positive Number
How many months ago was your account established:8
What is the interest rate of your account:100
What was the starting balance:100
--------- Month 0
What deposits did you make:1
What withdrawals did you make:0
Your balance is 16.8333
--------- Month 1
What deposits did you make:^C
vladimir@VladTop:~/DeAnzaCPP/Chapter 5$ g++ CIS22A_CH5_EX16_Kataev_Vladimir.cpp && ./a.out
How many months ago was your account established:-2.7
Enter a Positive Number
How many months ago was your account established:4
What is the interest rate of your account::100
What was the starting balance:-250
Enter a Positive Number
What was the starting balance:3000
--------- Month 0
What deposits did you make:100
What withdrawals did you make:90
Your balance is 3260.83
--------- Month 1
What deposits did you make:-80
Enter a Positive Number
What deposits did you make:80
What withdrawals did you make:200
Your balance is 3402.57
--------- Month 2
What deposits did you make:90
What withdrawals did you make:5000
Out of money, account closed


How many months ago was your account established:2
What is the interest rate of your account:17
What was the starting balance:100
--------- Month 0
What deposits did you make:0
What withdrawals did you make:0
Your balance is 101.417
--------- Month 1
What deposits did you make:12
What withdrawals did you make:10
Your balance is 104.882


*/
