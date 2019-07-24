/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<math.h>			
#include<string>			
using namespace std;			
int main(){				
	double w = 0.0, h = 0;
	cout << "Enter your weight(lbs):";cin >>w;
	cout << "Enter your height(inches)";cin >> h;
	cout << "Your BMI is "<<703*w / (pow(h,2)) << endl;
	if(703*w/pow(h,2) > 25){cout << "Youre are considered overweight\n";}
	if(703*w/pow(h,2) < 18.5){cout << "Youre are considered underweight\n";}
	return 0;				
}	
/*
Enter your weight(lbs):1
Enter your height(inches)68
Your BMI is 0.152033
Youre are considered underweight
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT5_Kataev_Vladimir.cpp && ./a.out
Enter your weight(lbs):130
Enter your height(inches)68
Your BMI is 19.7643
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT5_Kataev_Vladimir.cpp && ./a.out
Enter your weight(lbs):250
Enter your height(inches)68
Your BMI is 38.0082
Youre are considered overweight

*/
