#include<iostream>
#include<set>
#include<iterator>
using namespace std;


set<char> makeSet(int, const char*);

int main(int argc, char** argv){
	if(argc == 1 || argc > 2)
	{
		cout << "Wrong arg list\n";
		return 0;
	}

	set<char> toWorkWith;
	for(char* i = &argv[1][0]; *i != '\0'; i++){
		toWorkWith.insert(*i);
	}

	set<char>::iterator iter = toWorkWith.begin();
	for(iter = toWorkWith.begin(); iter != toWorkWith.end(); iter++)
		cout << *iter <<' ';
	cout << "\ndone\n";

	for(auto it : toWorkWith)
		cout << it << ' ';
	cout << "\ndunn\n";

	return 0;
}

