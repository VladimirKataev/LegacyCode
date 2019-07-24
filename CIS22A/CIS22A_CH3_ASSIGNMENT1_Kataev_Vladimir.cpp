/*
	Program made by Vladimir Kataev
	Does the assigned challenges
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;

string promptResponse(string request){	//Prompt func. to save code
	cout << request << endl;	//Don't put \n at end of param, it does it anyway
	string ans;
	getline(cin, ans);

	return ans;
}
int intResponse(string request){	//See above, but int
	cout << request << endl;
	int ans;
	cin >> ans;
	return ans;
}
double doubleResponse(string request){	//See above, but double
	cout << request << endl;
	double ans;
	cin >> ans;
	return ans;
}
void first(){
	double gallons = doubleResponse("How many gallons in are in your car's tank?");
	int miles = intResponse("How many miles can be covered on one tank?");
	cout << "Your car's average mpg is " << (double) miles / gallons << endl;
}
void second(){
	int classA = intResponse("How many Class A seats were sold?");
	int classB = intResponse("How many Class B seats were sold?");
	int classC = intResponse("How many Class C seats were sold?");
	cout << "The income made was $" << (classA * 15)+(classB * 12)+(classC * 9) << endl;
}
void third(){
	int a = intResponse("What was the score on your first test?");
	int b = intResponse("What was the score on your second test?");
	int c = intResponse("What was the score on your third test?");
	int d = intResponse("What was the score on your fourth test?");
	int e = intResponse("What was the score on your fifth test?");
	std::cout<<std::setprecision(3) << std::fixed << "Your average was " << (double)(a + b + c + d + e)/5.0 << endl;
}
void fourth(){
	string 	mon1 = promptResponse("What was the first month?");
	string	mon2 = promptResponse("What was the second month?");
	string	mon3 = promptResponse("What was the third month?");
	double 	rain1 = doubleResponse("How much rain fell the first month?"),
		rain2 = doubleResponse("How much rain fell the second month?"),
		rain3 = doubleResponse("How much rain fell the third month?");
	cout 	<< "The average rainfall for " << mon1 << ", " << mon2 << ", " << mon3<< ", was "
		<< (rain1 + rain2 + rain3)/3.0 << " inches"<< endl;
}
void fifth(){
	int 	men = intResponse("How many men are in the class?"),
		women = intResponse("How many women in the class?");
	cout 	<< 	"The percentage of men is " << (men * 100) / (men + women * 1.0) << "\n" <<
			"THe percentage of women is " << (women * 100) / (men + women *1.0) << "\n";
}
void sixth(){
	double propSugar = 1.5, propButter = 1, propFlour = 2.75;
	int cookiesNeeded = intResponse("How many cookies are needed?");
	cout << "You will need:\n" <<
		propSugar * (cookiesNeeded / 48.0) << " cups of sugar\n" <<
		propButter * (cookiesNeeded/ 48.0) << " cups of butter\n"<<
		propFlour * (cookiesNeeded / 48.0) << " cups of flour\n";
}
void seventh(){
	string movie = promptResponse("What is the name of the movie?");
	int	adultTickets = intResponse("How many adult tickets were sold?");
	int	childTickets = intResponse("How many child tickets were sold?");
	int	grossProfit = (adultTickets * 10) + (childTickets * 6),
		netProfit = grossProfit * 0.2,
		distributorPaid = grossProfit * 0.8;
	cout <<
		"Movie name:" << movie << "\n" <<
		"Adult tickets sold:" << adultTickets << endl <<
		"Child tickets sold:" << childTickets << endl <<
		"Gross Box Office Profit:$" << grossProfit << endl <<
		"Net Box Office Profit:$"<<netProfit << endl <<
		"Amount paid to Distrubutor:$"<<distributorPaid<<endl;
}
void eighth(){
	double
	 	palletWeight = doubleResponse("How much does a pallet weigh by itself?"),
		kerbWeight = doubleResponse("How much does the whole package weigh?");
	cout << "There are " << (int)((kerbWeight - palletWeight)/12.5) << " widgets\n";
}
void ninth(){
	int cookies = intResponse("How many cookies did you eat?");
	cout << "Total calories consumed:" << (cookies*30) << endl;
}
void tenth(){
	double value = doubleResponse("What is the value of the property?");
	cout << "You should insure it to " << value * 0.8 << "\n";
}
void eleventh(){
	double monthlyCost = doubleResponse("How much do you spend on your car in total monthly?");
	cout << "You spend " << monthlyCost * 12 << " On your car yearly\n";
}
void twelfth(){
	double celcius = doubleResponse("Enter Celsius:");
	cout << (9*celcius/5)+32 << "F\n";
}
void thirteenth(){
	double const yenPerDollar = 98.93,
	eurosPerDollar = 0.74;
	double input = doubleResponse("How many dollars are being traded?");
	cout << fixed <<showpoint << setprecision(2)
		<< "You could get\n"
		<< yenPerDollar* input << " Yen, or\n"
		<< eurosPerDollar* input << " Euroes\n";
}
void fourteenth(){
	string month= promptResponse("Enter the month:");
	int year = intResponse("Enter the year:");
	double collected = doubleResponse("Total collected:");
	cout << setprecision(2) << showpoint << fixed <<
		"Month:"<< month << endl <<
		"------------------\n" <<
		"Total collected:$" << collected << endl <<
		"Sales :$" << collected / 0.06 << endl <<
		"County sales tax :$" << collected / 0.02 << endl <<
		"State sales tax :$" << collected / 0.04 << endl <<
		"Total sales tax :$" << collected / 0.06 <<endl;
}/*
void fifteenth(){
	double value = doubleResponse("What is full value of property?");

}
void sixteenth(){

}*/
void seventeenth(){
	srand(time(NULL));
	int a = (int)(rand()%50), b = (int)(rand()%50);
	printf("What is the sum of %d and %d", a, b);
	int answer = intResponse("");

	cout << "The correct answer is " << a+b <<"\n";

}
int main(int argc, char** argv){
	first();
	cout << "\n end of prog \n";
	second();
	cout << "\n end of prog \n";
	third();
	cout << "\n end of prog \n";
	fourth();
	cout << "\n end of prog \n";
	fifth();
	cout << "\n end of prog \n";
	sixth();
	cout << "\n end of prog \n";
	seventh();
	cout << "\n end of prog \n";
	eighth();
	cout << "\n end of prog \n";
	ninth();
	cout << "\n end of prog \n";
	tenth();
	cout << "\n end of prog \n";
	eleventh();
	cout << "\n end of prog \n";
	twelfth();
	cout << "\n end of prog \n";
	thirteenth();
	cout << "\n end of prog \n";
	fourteenth();
	cout << "\n end of prog \n";
	seventeenth();
	return 0;
}
/*

How many gallons in are in your car's tank?
18.5
How many miles can be covered on one tank?
700
Your car's average mpg is 37.8378

 end of prog
How many Class A seats were sold?
45
How many Class B seats were sold?
53
How many Class C seats were sold?
43
The income made was $1698

 end of prog
What was the score on your first test?
77
What was the score on your second test?
88
What was the score on your third test?
99
What was the score on your fourth test?
79
What was the score on your fifth test?
98
Your average was 88.200

 end of prog
What was the first month?
What was the second month?
Feb
What was the third month?
March
How much rain fell the first month?
12
How much rain fell the second month?
13
How much rain fell the third month?
14
The average rainfall for , Feb, March, was 13.000 inches

 end of prog
How many men are in the class?
55
How many women in the class?
65
The percentage of men is 45.833
THe percentage of women is 54.167

 end of prog
How many cookies are needed?
700
You will need:
21.875 cups of sugar
14.583 cups of butter
40.104 cups of flour

 end of prog
What is the name of the movie?
How many adult tickets were sold?
54
How many child tickets were sold?
43
Movie name:
Adult tickets sold:54
Child tickets sold:43
Gross Box Office Profit:$798
Net Box Office Profit:$159
Amount paid to Distrubutor:$638

 end of prog
How much does a pallet weigh by itself?
45
How much does the whole package weigh?
900
There are 68 widgets

 end of prog
How many cookies did you eat?
56
Total calories consumed:1680

 end of prog
What is the value of the property?
1500000
You should insure it to 1200000.000

 end of prog
How much do you spend on your car in total monthly?
400
You spend 4800.000 On your car yearly

 end of prog
Enter Celsius:
40
104.000F

 end of prog
How many dollars are being traded?
54
You could get
5342.22 Yen, or
39.96 Euroes

 end of prog
Enter the month:
Enter the year:
2018
Total collected:
300
Month:
------------------
Total collected:$300.00
Sales :$5000.00
County sales tax :$15000.00
State sales tax :$7500.00
Total sales tax :$5000.00

 end of prog
What is the sum of 37 and 49

43
The correct answer is 86


*/
