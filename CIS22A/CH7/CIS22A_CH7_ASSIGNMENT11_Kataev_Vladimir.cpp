/*
	Written by Vladimir Kataev
*/
#include<iostream>
using namespace std;

void getScore(int&);
void calcAverage(int[]);
int findLowest(int[]);

int main(){
	int test[5];
	int a, b, c, d, e;
	getScore(a);
	getScore(b);
	getScore(c);
	getScore(d);
	getScore(e);

	test[0] = a;
	test[1] = b;
	test[2] = c;
	test[3] = d;
	test[4] = e;

	calcAverage(test);

	cout << "Lowest score was "<< findLowest(test) << endl;

	return 0;
}

void getScore(int &entry){
	do{
		cout << "Enter test score:"; cin >> entry;
	}while(entry < 0 || entry > 100);
}
void calcAverage(int a[]){
	cout << "Average is " << (a[1]+a[2]+a[3]+a[4]+a[0])/5.0 << endl;
}
int findLowest(int a[]){
	int ans = a[0];
	for(int i = 1; i < 5; i++){
		if(a[i] < ans)
			ans = a[i];
	}
	return ans;
}
/*
Enter test score:80
Enter test score:85
Enter test score:90
Enter test score:35
Enter test score:60
Average is 70
Lowest score was 35

Enter test score:99
Enter test score:100
Enter test score:100
Enter test score:30
Enter test score:30
Average is 71.8
Lowest score was 30


*/
