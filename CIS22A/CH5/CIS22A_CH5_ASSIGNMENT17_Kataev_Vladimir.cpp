/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	int date1, date2, date3;
	double jump1, jump2, jump3;
	bool used1 = false, used2=false, used3=false;
	do{
		cout << "Enter your first jump:"; cin >> jump1;
	}while(!(2.0 < jump1 && jump1 < 5));
	cout << "Date of that jump:"; cin >> date1;

	do{
		cout << "Enter your second jump:"; cin >> jump2;
	}while(!(2.0 < jump2 && jump2 < 5));
	cout << "Date of that jump:"; cin >> date2;

	do{
		cout << "Enter your third jump:"; cin >> jump3;
	}while(!(2.0 < jump3 && jump3 < 5));
	cout << "Date of that jump:"; cin >> date3;



	if(jump1 > jump2 && jump1 > jump3){used1 =true; cout << "Jump 1, "<< jump1<<", on " << date1 <<endl;}
	else if(jump2 > jump1 && jump2 > jump3){used2 =true; cout << "Jump 2, "<< jump2<<", on " << date2 <<endl;}
	else if(jump3 > jump2 && jump3 > jump1){used3 =true; cout << "Jump 3, "<< jump3<<", on " << date3 <<endl;}

	if(used1){
		if(jump2 > jump3){
			used2 = true;
			cout << "Jump 2, " << jump2 << ", on " << date2 << endl;
		}
		else{
			cout << "Jump 3, " << jump3 << ", on " << date3 << endl;
			used3 = true;
		}
	}
	else if(used2){
		if(jump1 > jump3){
			cout << "Jump 1, " << jump1 << ", on " << date1 << endl;
			used1 = true;
		}
		else{
			cout << "Jump 3, " << jump3 << ", on " << date3 << endl;
			used3 = true;
		}
	}
	else if(used3){
		if(jump1 > jump2){
			cout << "Jump 1, " << jump1 << ", on " << date1 << endl;
			used1 = true;
		}
		else{
			cout << "Jump 2, " << jump2 << ", on " << date2 << endl;
			used2 = true;
		}
	}


	if(used1 && used2){
		cout << "Jump 3, " << jump3 << ", on " << date3 << endl;
	}
	else if(used1 && used3){
		cout << "Jump 2, " << jump2 << ", on " << date2 << endl;
	}
	else if(used2 && used3){
		cout << "Jump 1, " << jump1 << ", on " << date1 << endl;
	}


	return 0;				
}	
/*
Enter your first jump:1.8
Enter your first jump:2.2
Date of that jump:911
Enter your second jump:4.9
Date of that jump:0806
Enter your third jump:3.2
Date of that jump:420
Jump 2, 4.9, on 806
Jump 3, 3.2, on 420
Jump 1, 2.2, on 911

*/
