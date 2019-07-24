#include<iostream>
//#include<string> //Needed because getline
using namespace std;

int stringLength(char* in){ //Returns length of char array, assuming it ends at \0. Includes \0 in length
	int a = 1;
	while(*(in+a) != '\0')
		a++;
	return a+1; //if the \0 is at index 3, there was an index 0. hence the +1
}
char* stringNCopy(char* in, char* out){//Copy from 2nd into first
	int a = 0;
	while(*(out+a) != '\0'){
		*(in+a) = *(out+a);
		a++;
	}
	*(in+a) = *(out+a);
	return in;
}
char* stringNAdd(char* orig, char* add){ // Appends the second into the first, affecting original
	int a = 0;
	int o = stringLength(orig)-1;

	while(*(add+a) != '\0')
		*(orig+o+a) = *(add+a++);
	*(orig+o+a) = *(add+a);
	return orig;
}

int stringNCompare(char* a, char* b){ 	//Compares a and b ASCII-tecally
	if(*a == '\0' && *b == '\0')
		return 0;

	if(*a == *b)	// If both start with same letter, recurse onto next letter
		return stringNCompare(a+1, b+1); 
	return int(*a - *b);
}
int main(){
	char* one = new char[1024]; char* two = new char [1024];
	int state=1;

	cout << "WARNING: do not enter space for any words. Requires getline, which doesn't accept char* as argument\n";

	while(state >0){
		do{
			cout << "Options:\n0:Exit\n1:Length\n2:Copy\n3:Add\n4:Compare\nEnter:";
			cin >> state;
		}while(state < 0 || state > 4);

		switch(state){
			case 0:
				break;
			case 1:
				cout << "Enter the phrase:";
				cin >> one;
				cout << "The length is " << stringLength(one) << endl;
				break;
			case 2:
                                cout << "Enter the first phrase:"; 
                                cin >> one;
                                cout << "Enter the second phrase:"; 
                                cin >> two;
				cout << "The result is:" << stringNCopy(one, two) << endl;
				break;
			case 3:
                                cout << "Enter the first phrase:"; 
                                cin >> one;
                                cout << "Enter the second phrase:"; 
                                cin >> two;
                                cout << "The result is:" << stringNAdd(one, two) << endl;
                                break;
			case 4:
                                cout << "Enter the first phrase:"; 
                                cin >> one;
                                cout << "Enter the second phrase:"; 
                                cin >> two;
                                cout << "The result is:" << stringNCompare(one, two) << endl;
                                break;
		}

	}

	delete []one; delete []two; //Clear your RAM kids

	return 1;
}




/* ----------TEST RUN-------------
WARNING: do not enter space for any words. Requires getline, which doesn't accept char* as argument
Options:
0:Exit
1:Length
2:Copy
3:Add
4:Compare
Enter:1
Enter the phrase:yeet
The length is 5
Options:
0:Exit
1:Length
2:Copy
3:Add
4:Compare
Enter:2
Enter the first phrase:Olof
Enter the second phrase:meisterchan
The result is:meisterchan
Options:
0:Exit
1:Length
2:Copy
3:Add
4:Compare
Enter:3
Enter the first phrase:Olof
Enter the second phrase:Meister
The result is:OlofMeister
Options:
0:Exit
1:Length
2:Copy
3:Add
4:Compare
Enter:4
Enter the first phrase:Alpha
Enter the second phrase:Bravo
The result is:-1
Options:
0:Exit
1:Length
2:Copy
3:Add
4:Compare
Enter:0
*/
