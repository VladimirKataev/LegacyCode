/*	Written By Vladimir Kataev
Does the specified assignment
*/
#include<iostream>			
#include<fstream>			
#include<string>			
using namespace std;			
int main(){				
	string colOne, colTwo;
	do{
		cout << "Enter First Colour:"; cin >> colOne;
	}while(colOne != "red" && colOne != "blue" && colOne != "green");
        do{
                cout << "Enter Second Colour:"; cin >> colTwo;
        }while(colTwo != "red" && colTwo != "blue" && colTwo != "yellow");



	if(colOne == "red"){
	//case "red":
		if(colTwo == "red")
			cout << "Mixing those gets you red\n";
		else if(colTwo == "yellow")
			cout << "Mixing those gets you orange\n";
		else
			cout << "Mixing those gets you purple\n";
	}
	if(colOne == "blue"){
//		case "blue":
		if(colTwo == "red")
			cout << "Mixing those gets you purple\n";
		else if(colTwo == "blue")
			cout << "Mixing those gets you blue\n";
		else
			cout << "Mixing those gets you green\n";
	}
	if(colOne == "yellow"){
		if(colTwo == "red")
			cout << "Mixing those gets you orange\n";
		else if(colTwo == "blue")
			cout << "Mixing those gets you green\n";
		else
			cout << "Mixing those gets you yellow\n";
	}
	return 0;
}
/*
Enter First Colour:red
Enter Second Colour:blue
Mixing those gets you purple

Enter First Colour:Kowalski
Enter First Colour:Analisys
Enter First Colour:blue
Enter Second Colour:blue
Mixing those gets you blue


*/
