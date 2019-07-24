/*
	Written by Vladimir Kataev
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

int getAction();
void runGame();

int main(){
	srand(time(NULL));
	runGame();

	return 0;
}
void runGame(){
	int aiChoice = rand()%3; //0 R, 1 P, 2 S
	int pChoice = getAction();
	switch(aiChoice){
		case 0:	cout << "Computer Chose Rock\n"; break;
		case 1:	cout << "Computer Chose Paper\n"; break;
		case 2:	cout << "Computer Chose Scissors\n"; break;
	}
	if(	(aiChoice == 0 && pChoice == 2) || //PC beats human
		(aiChoice == 1 && pChoice == 0) ||
		(aiChoice == 2 && pChoice == 1)){

		cout << "PC Wins\n";
		return;
	}




	else if(aiChoice == pChoice){	// draw
		cout << "Play Again\n";
		runGame();//recurse
		return;
	}
	else{
		cout << "You Win\n";

	}
	return;
}
int getAction(){
	cout << "Pick one:\n0 for rock\n1 for paper\n2 for scissors\n";
	int ans;
	do{
		cout << "Enter Value:"; cin >> ans;

	}while(ans < 0 || ans > 2);
	return ans;

}
/*
Pick one:
0 for rock
1 for paper
2 for scissors
Enter Value:-1
Enter Value:0
Computer Chose Scissors
You Win
vladimir@VladTop:~/DeAnzaCPP/CH7$ g++ -std=c++11 CIS22A_CH7_ASSIGNMENT24_Kataev_Vladimir.cpp && ./a.out
Pick one:
0 for rock
1 for paper
2 for scissors
Enter Value:2
Computer Chose Rock
PC Wins
vladimir@VladTop:~/DeAnzaCPP/CH7$ g++ -std=c++11 CIS22A_CH7_ASSIGNMENT24_Kataev_Vladimir.cpp && ./a.out
Pick one:
0 for rock
1 for paper
2 for scissors
Enter Value:2
Computer Chose Scissors
Play Again
Pick one:
0 for rock
1 for paper
2 for scissors
Enter Value:0
Computer Chose Paper
PC Wins

*/
