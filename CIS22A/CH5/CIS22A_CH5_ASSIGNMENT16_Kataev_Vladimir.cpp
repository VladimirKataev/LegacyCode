/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	double time1, time2, time3;

	do{cout << "Enter time 1:"; cin >> time1;}while(time1 < 0);
	do{cout << "Enter time 2:"; cin >> time2;}while(time2 < 0);
	do{cout << "Enter time 3:"; cin >> time3;}while(time3 < 0);

	if(time1 < time2 && time1 < time3){cout << "#1 was fastest\n";}
	else if(time2 < time1 && time2 < time3){cout << "#2 was fastest\n";}
	else if(time3 < time2 && time3 < time1){cout << "#3 was fastest\n";}


	return 0;				
}	
/*
Enter time 1:2.0
Enter time 2:1.9
Enter time 3:1.7
#3 was fastest

Enter time 1:1
Enter time 2:2
Enter time 3:3
#1 was fastest

*/
