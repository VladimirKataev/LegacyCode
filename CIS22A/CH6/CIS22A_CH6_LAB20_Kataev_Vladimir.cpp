/*
	Written by Vladimir Kataev
*/
#include<iostream>
using namespace std;

// Global constant
const int BIRDS = 500;

// Function prototype
void california();

int main()
{
	cout << "In main there are " << BIRDS << " birds.\n"; 
	california();
	return 0;
}



// california function
void california() {
	const int BIRDS = 10000;
	cout << "In california there are " << BIRDS << " birds.\n";
}


/*
In main there are 500 birds.
In california there are 10000 birds.

*/
