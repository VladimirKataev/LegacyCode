/*
	Written by Vladimir Kataev
	Does error checking
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	string in;
	ifstream inputFile;
	inputFile.open("BadListOfNumbers.txt");
	if(!inputFile){
		cout << "Error reading file\n";
		return 1;	//return 1 for actual errors
	}
	while(inputFile>>in)
		cout << in << endl;
	inputFile.close();
	return 0;
}
