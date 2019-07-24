/*
Written by VLadimir Kataev
*/
#include<iostream>
#include<fstream>
using namespace std;

int main(){
	long total = 0;
	long n = 0;
	double avg;
	int curr;
	fstream in;
	in.open("Random.txt");
	if(!in){
		cout << "File errors";
		return 1;
	}

	while(in >> curr){
		total += curr;
		n++;
	}

	cout << "Numbers:" << n << endl <<
		"Total:" << total << endl <<
		"Average:" << 1.0 * total / n << endl;

	return 0;
}
/*

Numbers:200
Total:105527
Average:527.635


*/
