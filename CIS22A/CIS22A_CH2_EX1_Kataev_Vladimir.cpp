//						Vladimir Kataev
//					Calculates size of Paycheck

#include<iostream>
using namespace std;
int main(){
	double hours, ratePerHour;
	hours = 31;
	ratePerHour = 92.50;
	string company = "De Anza College";
						//     Calculation occurs here
						//	    \/ \/ \/ \/ \/
	cout << "Your " << company << " gross pay is " << hours * ratePerHour << " dollars. \n";	//Output
	return 0;
}
