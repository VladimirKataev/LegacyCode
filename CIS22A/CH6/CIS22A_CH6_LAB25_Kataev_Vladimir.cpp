/*
	Written by Vladimir Kataev
*/
#include<iostream>
using namespace std;

void doubler(int&);

int main(){

	int use = 4;
	cout << "Use is " << use << endl;
	doubler(use);
	cout << "Use is " << use << endl;

}

void doubler(int& in){
	cout << "doubled"<< endl;
	in *= 2;
}
/*
Use is 4
doubled
Use is 8
*/
