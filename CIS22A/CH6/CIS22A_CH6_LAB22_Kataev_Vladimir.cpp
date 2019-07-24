/*
	Written by Vladimir Kataev
*/
#include<iostream>
using namespace std;

void showStatic();

int main(){
	for(int i = 0; i < 5; i++){
		showStatic();
	}
	cout << endl;
	return 0;

}

void showStatic(){
	static int yes = 5;
	cout << "Value of static int:"<<yes++<<endl;
}
/*
Value of static int:5
Value of static int:6
Value of static int:7
Value of static int:8
Value of static int:9

*/
