/*
	Vladimir Kataev
	This does user i, file o
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	ifstream inputFile;
	string filename, next;
	cout << "Enter a filename\n";
	cin >> filename;

	inputFile.open(filename.c_str());
	if(!inputFile){
		cout << "No such file, or read issues\n";
		return 1; //return 1 for actual errors
	}

	while(inputFile >> next)
		cout << next << endl;
	inputFile.close();
	return 0;
}
