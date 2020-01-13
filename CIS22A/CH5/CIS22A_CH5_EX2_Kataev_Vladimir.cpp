/*
	This was made by Vladimir Kataev
*/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	int hours, rate, pay;
	string company;
	srand(time(NULL));
	cout << "Enter Company name:"; getline(cin, company);


	do{
		cout << "Enter Hours worked:"; cin >> hours;
	}while(hours < 0 || hours > 168);

	do{
		cout << "Enter paid rate: ";cin >> rate;
	}while(rate <= 0);
	pay  =  (hours < 40)? (hours * rate): ((rate * 40) + (1.5*rate*(hours - 40)));


	cout 	<< "Company: " << company << endl 
		<< "Hours:"<<hours << endl
		<< "Rate:"<<rate<<endl
		<< "Document Number:" << (rand()%1000) + 1000
		<< endl
		<< endl
		<< "Your "<<company<<" Gross pay is $" << pay
		<< endl;
}
/*
Enter Company name:De Anza
Enter Hours worked:-3
Enter Hours worked:-5
Enter Hours worked:13
Enter paid rate: 1
Company: De Anza
Hours:13
Rate:1
Document Number:1325

Your De Anza Gross pay is $13


Enter Company name:Gewgl
Enter Hours worked:41
Enter paid rate: 1
Company: Gewgl
Hours:41
Rate:1
Document Number:1763

Your Gewgl Gross pay is $41

*/
