/*Written by Vladimir Kataev*/
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;

int main(){
	int bar, year = 1900;
	fstream read;
	read.open("People.txt");
	if(!read){
		cout << "File issues\n";
		return 1;
	}
	cout << "PRARIEVILLE POPULATION GROWTH";
	while(read >> bar){
		cout << year << ":";
		for(int a = 0; a < bar / 1000;a++)
			cout << "*";
		cout << endl;
		year += 20;

	}
	return 0;
}
/*
PRARIEVILLE POPULATION GROWTH
1920:****
1940:*****
1960:*********
1980:**************
2000:******************
2020:******************


*/
