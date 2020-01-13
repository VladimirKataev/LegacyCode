/*
	Vladimir Kataev
	This program does file io
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	ofstream outputFile;
	string name1, name2, name3;
	outputFile.open("Friends.txt");
	if(!outputFile){
		return 1; //return 1 for actual errors
	}
	cout << "Enter the names of 3 friends:\n#1 ";
	cin >> name1;
	cout << "#2 ";
	cin >> name2;
	cout << "#3 ";
	cin >> name3;

	//Write out
	outputFile << name1 << endl ;
	outputFile << name2 << endl ;
	outputFile << name3 << endl ;

	outputFile.close();
	return 0;
}
/*
vladimir@VladTop:~/DeAnzaCPP$ g++ -o CH5EX18 CIS22A_CH5_EX18_Kataev_Vladimir.cpp && ./CH5EX18
Enter the names of 3 friends:
#1 Me
#2 Myself
#3 I
*/
