/*
	Written by Vladimir Katae
	Menu driven prog
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

void dispMenu(string[], double[], int);// names, prices, iterator
double calcBill(int[], double[],int);//Input is the array of purchases, array of cost, iterator
void printBill(double, double);//Input is pre-tax bill, tax

int main(){
	double PRICES[] = {5.25, 5.75, 5.95, 5.05, 5.95};	//Initialisation
	int NUMBER_ITEMS_SOLD = 5;
	string NAMES[] = {
		"De Anza Burger",
		"Bacon Cheese",
		"Mushroom Swiss",
		"Western Burger",
		"Don Cali Bruger"
		};
	const double tax = 0.09;
	int choice;
	int purchases[] = {0,0,0,0,0};	//Record of what's been bought
	bool done = false;


	srand(time(NULL));
	int fileID = 1000 + (rand() % 1000);
	string fileName = to_string(fileID);


	do{
		dispMenu(NAMES, PRICES, NUMBER_ITEMS_SOLD);
		cout << "Enter Your Choice (or 0 to exit):";
		cin >> choice;
		switch(choice){
			case 0:
				done = true;
				break;
			case 1:

				cout << "Added a #" << choice<<endl;
				purchases[choice-1] += 1;
				break;
			case 2:

				cout << "Added a #" << choice<<endl;
				purchases[choice-1] += 1;
				break;
			case 3:

				cout << "Added a #" << choice<<endl;
				purchases[choice-1] += 1;
				break;
			case 4:

				cout << "Added a #" << choice<<endl;
				purchases[choice-1] += 1;
				break;
			case 5:

				cout << "Added a #" << choice<<endl;
				purchases[choice-1] += 1;
				break;


			default:
				cout << "Enter a valid number\n";
		}


	}while(!done);

	printBill(calcBill(purchases, PRICES, NUMBER_ITEMS_SOLD), tax);


	//-------------file writey stuff
	ofstream writer;
	writer.open(fileName + ".txt");
	if(!writer){
		cout << "File issues\n";
		return 1;
	}

	for(int a = 0; a < NUMBER_ITEMS_SOLD; a++){
		writer << purchases[a] << "*"<< PRICES[a]<<endl;
	}
	writer << calcBill(purchases, PRICES, NUMBER_ITEMS_SOLD);
	writer.close();


	return 0;
}
void dispMenu(string title[], double cost[], int t){
	cout << fixed << setprecision(2);
	for(int a = 0; a < t; a++ )
		cout << a+1 << ": "<< title[a] << " :$" << cost[a] << endl;
}
void printBill(double input, double tax){
	cout << fixed << setprecision(2);
	cout << "Pre-Tax:$" << input << endl << "Post-Tax:$" << (input * (1+tax)) << endl;
}
double calcBill(int bought[], double cost[], int t){
	double ans = 0;
	for(int a = 0; a < t; a++)
		ans += bought[a]*cost[a];
	return ans;
}
/*
1: De Anza Burger :$5.25
2: Bacon Cheese :$5.75
3: Mushroom Swiss :$5.95
4: Western Burger :$5.05
5: Don Cali Bruger :$5.95
Enter Your Choice (or 0 to exit):1
Added a #1
1: De Anza Burger :$5.25
2: Bacon Cheese :$5.75
3: Mushroom Swiss :$5.95
4: Western Burger :$5.05
5: Don Cali Bruger :$5.95
Enter Your Choice (or 0 to exit):2
Added a #2
1: De Anza Burger :$5.25
2: Bacon Cheese :$5.75
3: Mushroom Swiss :$5.95
4: Western Burger :$5.05
5: Don Cali Bruger :$5.95
Enter Your Choice (or 0 to exit):-1
Enter a valid number
1: De Anza Burger :$5.25
2: Bacon Cheese :$5.75
3: Mushroom Swiss :$5.95
4: Western Burger :$5.05
5: Don Cali Bruger :$5.95
Enter Your Choice (or 0 to exit):9
Enter a valid number
1: De Anza Burger :$5.25
2: Bacon Cheese :$5.75
3: Mushroom Swiss :$5.95
4: Western Burger :$5.05
5: Don Cali Bruger :$5.95
Enter Your Choice (or 0 to exit):3
Added a #3
1: De Anza Burger :$5.25
2: Bacon Cheese :$5.75
3: Mushroom Swiss :$5.95
4: Western Burger :$5.05
5: Don Cali Bruger :$5.95
Enter Your Choice (or 0 to exit):0
Pre-Tax:$16.95
Post-Tax:$18.48
vladimir@VladTop:~/DeAnzaCPP/final$ g++ -std=c++11 CIS22A_Final_Kataev_Vladimir.cpp && ./a.out
1: De Anza Burger :$5.25
2: Bacon Cheese :$5.75
3: Mushroom Swiss :$5.95
4: Western Burger :$5.05
5: Don Cali Bruger :$5.95
Enter Your Choice (or 0 to exit):3
Added a #3
1: De Anza Burger :$5.25
2: Bacon Cheese :$5.75
3: Mushroom Swiss :$5.95
4: Western Burger :$5.05
5: Don Cali Bruger :$5.95
Enter Your Choice (or 0 to exit):5
Added a #5
1: De Anza Burger :$5.25
2: Bacon Cheese :$5.75
3: Mushroom Swiss :$5.95
4: Western Burger :$5.05
5: Don Cali Bruger :$5.95
Enter Your Choice (or 0 to exit):1
Added a #1
1: De Anza Burger :$5.25
2: Bacon Cheese :$5.75
3: Mushroom Swiss :$5.95
4: Western Burger :$5.05
5: Don Cali Bruger :$5.95
Enter Your Choice (or 0 to exit):0
Pre-Tax:$17.15
Post-Tax:$18.69



*/
