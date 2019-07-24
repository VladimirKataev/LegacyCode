/*
	Code Written by Vladimir Kataev
	Assignment of various tasks as outlined on Canvas

*/

#include<iostream>
using namespace std;

//	Store 50 & 100 in 2 int vars, and a "total" var
void first(){
	int a = 50;
	int b = 100;
	int total = a+b;
}

void second(){
	long revenue = 8600000;
	double production = 0.58;	// 58% = 58/100 = 0.58
	double prediction = revenue * production;
	cout << "The East Coast sales division will make " << prediction << " dollars this year\n";
}

void third(){
	double purchase = 95;	// double as purchases can be 94.99
	double netTax = 1.06;	// total tax of 6%, 100% + 6% = 106% = 106/100 = 1.06
	cout << "total payment is $"<< purchase*netTax <<"\n";
}
void fourth(){
	double mealCost = 88.67;
	double mealPostTax = mealCost * 1.0675;
	double mealPostTip = mealPostTax * 1.2;

	cout 	<< "Cost:$" << mealCost				//Multi-line
		<< "\n Tax:$" << mealCost * 0.0675		//Code for
		<< "\n Total Bill:$" << mealPostTip << "\n";	//Readability
}
void fifth(){
	double a = 28; double b = 32; double c = 37; double d = 24; double e = 33;
	double sum = a + b + c+ d + e;
	cout << sum/5 <<"\n";
}
void sixth(){
	double payAmount = 2200.0;
	int payPeriods = 26;
	double annualPay = payAmount*payPeriods;
	cout << "Annual pay:$"<< annualPay <<"\n";
}
void seventh(){
	double rise = 1.5;
	cout<<"5 Year's rise:" <<rise * 5;
	cout<<"\n 7 Year's rise:"<< rise *7;
	cout<<"\n 10 Year's rise:" << rise *10 << "\n";
}
void eighth(){
	double item1 = 15.95;
	double item2 = 24.95;
	double item3 = 6.95;
	double item4 = 12.95;
	double item5 = 3.95;
	double total = item1 + item2+item3+item4+item5;
	cout <<						//Multi-line print
		"Item 1:$" << item1  << "\n" <<
		"Item 2:$" << item2  << "\n" <<
		"Item 3:$" << item3  << "\n" <<
		"Item 4:$" << item4  << "\n" <<
		"Item 5:$" << item5  << "\n" <<
		"Subtotal = $" << total << "\n" <<
		"Sales tax = $" << total * 0.07 << "\n" <<
		"Total = $" << total * 1.07 << "\n";		//Math to get a 7% tax
}
void ninth(){
	cout <<						//Multi-line print
		"Char bytes:" << sizeof(char) << "\n" <<
		"Int bytes:" << sizeof(int) << "\n" <<
		"Float bytes:" << sizeof(float) << "\n" <<
		"Double bytes:" << sizeof(double) << "\n";
}
void tenth(){
	double tankSize = 15.0;
	double distance = 375.0;
	cout << "MPG:" << distance/tankSize << "\n";
}

void eleventh(){
	double tankSize = 20.0;
	double townMPG = 23.5;
	double hwyMPG = 28.9;
	cout <<
		"City distance:" << tankSize*townMPG << "\n" <<
		"Highway distance:" << tankSize*hwyMPG << "\n";
}
void twelfth(){
	double acreSize = 43560;
	cout << 391876.0/acreSize << "Acres in 391876 ft^2\n";
}
void thirteenth(){
	// 35 % profit implies sell = 1.35 * value
	double value = 14.95;
	cout << "Selling price = $" << value*1.35 << "\n";
}
void fifteenth(){
	for(int i = 0; i < 4; i++){//prints row
		for(int j = 3-i; j > 0; j--){
			cout << " ";
		}
		for(int j = 1 + (2*i); j > 0; j--){
			cout << "*";
		}
		for(int j = 3-i; j > 0; j--){
			cout <<" ";
		}
		cout << "\n";
	}
}
void sixteenth(){
	fifteenth();
	for(int i = 1; i < 4; i++){
		for(int j = 0; j < i; j++){
			cout << " ";
		}
		for(int j = 7 - (2*i); j > 0; j--){
			cout << "*";
		}
		for(int j = 0 ; j < i; j++){
			cout << " ";
		}
		cout << "\n";
	}
}
void seventeenth(){
	double stocks = 750.0;
	double stockValue = 35.00;
	cout <<
		"Stocks net Value:$" << stocks*stockValue << "\n" <<
		"Commission Value:$" << (stocks*stockValue)*0.02 << "\n"<<
		"Total payment:$" << (stocks*stockValue)*1.02 << "\n";
}


int main(int argc, char** argv){

	first();
	second();
	third();
	fourth();
	fifth();
	sixth();
	seventh();
	eighth();
	ninth();
	tenth();
	eleventh();
	twelfth();
	thirteenth();
	fifteenth();
	sixteenth();
	seventeenth();

	return 0;
}
/* -----OUTPUT-----------
The East Coast sales division will make 4.988e+06 dollars this year
total payment is $100.7
Cost:$88.67
 Tax:$5.98523
 Total Bill:$113.586
30.8
Annual pay:$57200
5 Year's rise:7.5
 7 Year's rise:10.5
 10 Year's rise:15
Item 1:$15.95
Item 2:$24.95
Item 3:$6.95
Item 4:$12.95
Item 5:$3.95
Subtotal = $64.75
Sales tax = $4.5325
Total = $69.2825
Char bytes:1
Int bytes:4
Float bytes:4
Double bytes:8
MPG:25
City distance:470
Highway distance:578
8.99624Acres in 391876 ft^2
Selling price = $20.1825
   *
  ***
 *****
*******
   *
  ***
 *****
*******
 *****
  ***
   *
Stocks net Value:$26250
Commission Value:$525
Total payment:$26775
*/
