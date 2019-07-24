/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	double fat, calories;
	do{cout << "Enter fat(g):"; cin >> fat;}while(fat < 0);
	do{cout << "Enter Calories:"; cin >> calories;}while(calories < 0);

	cout << "The percentage of calories from fat is " << 9.0*fat/calories << endl;
	if(9.0*fat > calories) cout << "Something doesn't seem right\n";
	else if(9.0*fat/calories < 0.3) cout << "Low fat food\n";

	return 0;				
}	
/*
Enter fat(g):2
Enter Calories:15
The percentage of calories from fat is 1.2
Something doesn't seem right

Enter fat(g):-2
Enter fat(g):-3
Enter fat(g):1
Enter Calories:100
The percentage of calories from fat is 0.09
Low fat food

*/
