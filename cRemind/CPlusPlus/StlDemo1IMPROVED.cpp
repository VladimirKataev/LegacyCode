#include<iostream>
#include<set>
#include<iterator>
using namespace std;


set<char>* makeSet( char*);


int main(int argc, char** argv){
	if(argc == 1 || argc > 2)
	{
		cout << "Wrong arg list\n";
		return 0;
	}

	set<char>* toWorkWith = makeSet(argv[1]);

	/*
	for(char* i = &argv[1][0]; *i != '\0'; i++){
		toWorkWith.insert(*i);
	}
	*/


	set<char>::iterator iter = toWorkWith->begin();
	for(iter = toWorkWith->begin(); iter != toWorkWith->end(); iter++)
		cout << *iter <<' ';
	cout << "\ndone\n";



	delete toWorkWith;

	return 0;
}


set<char>* makeSet(char* in){
	set<char>* toRet = new set<char>;
	for(char* i = in; *i != '\0';i++){
		toRet->insert(*i);
	}
	return toRet;
}
