/*
	Written By Vladimir Kataev for CIS 22B
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
/*
FUNCTION string getUserInput (Because code reuse)

FUNCTION stringArr sort (returns array, duplicated but sorted)
->FUNCTION int FindMin (return index of lowest word)



FUNCTION procure (Returns array, having gone through all the single discarded chars)

FUNCTION fileOUT
*/



const int SIZE = 1024; //const because input must be 1024
int taken = 0;
string userInput(string prompt){
	cout << prompt << endl;
	string ans;
	getline(cin, ans);
	return ans;
}


/*------------RELIC OF EXPIRED TIMES
string[] getFile(ifstream read){
	int c = 0;
	string ans[SIZE];
	string tmp;
	while(getline(read, tmp, ' ') && c < 1023){

		//Curate for single characters
		if(strlen(tmp) == 1)
			break;

		ans[c++] = tmp;
	}
	return ans;
}--------------------------------------------
*/


int findMin(string search[SIZE], int s = 0){
	int ans = s;
	for(int a = s; a < SIZE; a++){
		if(search[a] < search[ans])
			ans = a;
	}
	//cout << s<<" "; // remnants of debugging
	return ans;
}

void selectionSort(string search[SIZE]){
	string tmp;
	int swp;
	for(int a = 0; a < SIZE; a++){
		swp = findMin(search, a);
		tmp = search[swp];
		search[swp] = search[a];
		search[a] = tmp;
	}

}

void output (string msg, ofstream fout){
	cout << msg << endl;
	fout << msg << endl;
}

int binarySearch(string search[], string term, int l = 0, int m = SIZE-1){
	int half = (l+m)/2;
	//cout << "launched this," <<l<< " " <<m<< " "<<half<<endl;
	if(search[half] == term){
		//cout << "is " << half;
		return half;
	}
	else if(l == m)
		return -1;
	else if(term > search[half])
		return binarySearch(search,term,half+1, m);
	else
		return binarySearch(search,term, l, half-1);
}



int main(){
	string words[SIZE];
	int taken = 0;
	string ifile = userInput("Where/what is the 'GLOBAL' input file?");
	ifstream instream(ifile);
	string ofile = userInput("Where/how to save the 'GLOBAL' output file?");
	ofstream outstream(ofile);

	if(!instream && !outstream){
		cout << "File error";
		return 1; //issues
	}



	string tmp;

	//
	cout << "The file's contents are:\n";
	for(int a = 0; a < SIZE; a++){
		tmp = "";
		instream >> tmp;
		if(tmp.size() > 1){
			words[a] = tmp;
			cout << words[a] << " ";
			outstream << words[a] << " ";
			taken++;
		}
	}


	selectionSort(words);
	cout << "\nThe sorted array is:\n";
	for(int a = 0; a < SIZE; a++)
		cout << words[a] << ",";
	cout << endl;

//	SIZE = taken;


	string srch;
	bool done = false;
	int pos;
	while(!done){
		cout << "Enter a search term (or the safeword, no):"; cin >> srch;
		if(srch == "no")
			done = true;
		else{
			//cout << "got here";
			pos = binarySearch(words, srch);
			if(pos == -1)
				cout << "Sorry, not found\n";
			else
				cout << "Found, at list position " << pos << endl;
		}
	}


	instream.close();
	outstream.close();
	return 0;
}

