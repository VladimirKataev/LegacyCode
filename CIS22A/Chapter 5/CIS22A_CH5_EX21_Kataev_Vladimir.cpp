/*Written By Vladimir Kataev*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
        srand(time(NULL));
        int secret = (rand()%100)+1;
        int attempt = 0;
	int brutes = 0;
        do{
                cout << "Enter your guess:"; cin >> attempt;
		brutes++;
                if(attempt == secret)
                        break;

                else if(attempt > secret)
                        cout << "Too high\n";
                else
                        cout << "Too low\n";

        }
        while(attempt!=secret);


        cout << "Correct guess, after " << brutes << " guesses\n";
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
Correct guess, after 5 guesses

Enter your guess:50
Too low
Enter your guess:75
Too low
Enter your guess:87
Too low
Enter your guess:93
Too low
Enter your guess:97
Too low
Enter your guess:99
Too low
Enter your guess:100
Correct guess, after 7 guesses

*/
