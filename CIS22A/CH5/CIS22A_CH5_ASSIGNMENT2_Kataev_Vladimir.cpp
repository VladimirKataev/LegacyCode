/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	int a = -1;
	while(!(a >=1 && a <= 10))
	{
		cout << "Enter a Number (1-10):";
		cin >> a;
	}
	switch(a){
		case 1:
			cout << "I";
			break;
		case 2: 
			cout << "II";
			break;
		case 3: 
			cout << "III";
			break;
		case 4: 
			cout << "IV";
			break;
		case 5: 
			cout << "V";
			break;
		case 6: 
			cout << "VI";
			break;
		case 7: 
			cout << "VII";
			break;
		case 8: 
			cout << "IIX";
			break;
		case 9: 
			cout << "IX";
			break;
		case 10: 
			cout << "X";
			break;

	}
	cout << endl;
	return 0;
}
/*
Enter a Number (1-10):0
Enter a Number (1-10):4
IV

*/
