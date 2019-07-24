/*
	Vladimir Kataev

*/

#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	const double MIN_INCOME = 3500.0;
	const int MIN_YEARS = 5;
	double income;
	int years;
	cout << "How many years did you spend at your current job?\n";
	cin >> years;
	cout << "What is your annual income?\n";
	cin >> income;
	if(years >= MIN_YEARS || income >= MIN_INCOME){
		cout << "You are qualified\n";
	}
	else{
		cout << "Either work for over " << MIN_YEARS << " years\n" <<
			"Or earn over " << MIN_INCOME << endl;
	}

	return 0;

}
/*
How many years did you spend at your current job?
1
What is your annual income?
2
Either work for over 5 years
Or earn over 3500
vladimir@VladTop:~/DeAnzaCPP$ ./a.out
How many years did you spend at your current job?
100 
What is your annual income?
30000
You are qualified

*/
