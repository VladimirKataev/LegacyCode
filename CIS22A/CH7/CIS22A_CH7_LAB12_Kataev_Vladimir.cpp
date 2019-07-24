/*
	Written by Vladimir Kataev
*/
#include<iostream>
using namespace std;

int main(){
	const int SIZE = 5;
	int nos[5];

	for(int &val: nos){
		cout << "Enter an int:";cin >> val;
	}
	cout << "\nDisplaying Values:\n";

	for(int val: nos)
		cout << val << endl;

	return 0;
}
/*
Enter an int:12
Enter an int:13
Enter an int:14
Enter an int:15
Enter an int:16

Displaying Values:
12
13
14
15
16

Enter an int:1
Enter an int:2
Enter an int:2
Enter an int:3
Enter an int:4

Displaying Values:
1
2
2
3
4


*/
