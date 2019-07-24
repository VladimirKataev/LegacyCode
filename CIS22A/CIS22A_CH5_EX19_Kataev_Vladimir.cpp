/*
	Written by VLadimir Kataev
	Does file io, mostly o
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	ifstream inputFile;
	string name;

	inputFile.open("Friends.txt");
	if(!inputFile){
		cout << "File Error";
		return 1; //return 1 is for actual errors
	}
	cout << "Reading file:\n";
	while(inputFile>>name){
		cout << name << endl;
	}
	inputFile.close();
	return 0;
}
/*
vladimir@VladTop:~/DeAnzaCPP$ g++ -o CH5EX19 CIS22A_CH5_EX19_Kataev_Vladimir.cpp && ./CH5EX19
Reading file:
Me
Myself
I
*/
