/*
	Written By Vladimir Kataev
	Does the exercise
	uses a file (or creates one) to store a list of user-entered friends
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	string filename, tmp;
	ofstream outputFile;
	int number, count=0;

	cout << "Enter a filename:\n";
	cin >> filename;
	outputFile.open(filename.c_str());


	cout << "How many friends you want to enter?\n";
	cin >> number;

	if(!outputFile){
		cout << "File not found, or errors reading";
		return 1; //return 1 for if an error happened
	}
	while(count < number){
		cout << "Enter a friend:\n";
		cin >> tmp;
		outputFile << tmp << endl;
		count++;
	}
	outputFile.close();

//----------------------------------------
	cout << "Reread check\n";

	ifstream inputFile;
	inputFile.open(filename.c_str());
	if(!inputFile){
		cout << "File read issues, or wrong name\n";
		return 1; //return 1 for if error happened
	}
	while(inputFile >> tmp)
		cout << tmp << endl;
	inputFile.close();

	return 0;
}
/*
Enter a filename:
huh
How many friends you want to enter?
3
Enter a friend:
me
Enter a friend:
myself
Enter a friend:
i
Reread check
me
myself
i
*/
