/*Written By Vladimir Kataev*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
	srand(time(NULL));
	int secret = (rand()%100)+1;
	int attempt = 0;

	do{
		cout << "Enter your guess:"; cin >> attempt;

		if(attempt == secret)
			break;

		else if(attempt > secret)
			cout << "Too high\n";
		else
			cout << "Too low\n";

	}
	while(attempt!=secret);


	cout << "Correct guess\n";
	return 0;

}
/*
Enter your guess:50
Too high
Enter your guess:25
Too high
Enter your guess:12
Too high
Enter your guess:6
Too high
Enter your guess:3
Too high
Enter your guess:1
Too low
Enter your guess:2
Correct guess


Enter your guess:50
Too high
Enter your guess:35
Too high
Enter your guess:25
Too high
Enter your guess:2
Too low
Enter your guess:12
Too low
Enter your guess:18
Too high
Enter your guess:15
Too high
Enter your guess:14
Correct guess


*/
