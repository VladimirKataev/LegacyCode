/*
	Written by Vladimir Kataev
*/
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void coinToss();

int main(){
	int throws;
	cout << "How Many Tosses:"; cin >> throws;
	srand(time(NULL));

	for(int a = 0; a < throws; a++)
		coinToss();

	return 0;
}
void coinToss(){//retrurns if a cointoss
	//cout << (rand()%2);
	((rand() % 2) == 0) ? cout << "heads\n": cout << "tails\n";

}
/*
How Many Tosses:6
tails
heads
heads
heads
heads
heads

How Many Tosses:10
tails
tails
heads
heads
heads
tails
tails
tails
heads
tails

*/
