#include<iostream>
#include"date.h"
using namespace std;


int main(){
	Date a;
	Date b(6,8,1999);
	cout << (a<b) << endl;
	return 0;
}
