/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	int s = 0;
	cout << "Enter a Number of seconds:"; cin >> s;
	if(s < 60){cout << "There are " << s << " Seconds\n";}
	if(60 <= s && s <= 3600){cout << "There are " << s / 60<<" minutes in that period\n";}
	if(3600 <= s && s <= 86400){cout << "There are " << s / 3600<<" hours in that period\n";}
	if(86400 <= s){cout << "There are " << s / 86400<<" days in that period\n";}
	return 0;				
}	
/*
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT7_Kataev_Vladimir.cpp && ./a.out
Enter a Number of seconds:120
There are 2 minutes in that period
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT7_Kataev_Vladimir.cpp && ./a.out
Enter a Number of seconds:6789342
There are 78 days in that period
vladimir@VladTop:~/DeAnzaCPP/CH5$ g++ CIS22A_CH5_ASSIGNMENT7_Kataev_Vladimir.cpp && ./a.out
Enter a Number of seconds:2
There are 2 Seconds
vladimir@VladTop:~/DeAnzaCPP/CH5$ 

*/
