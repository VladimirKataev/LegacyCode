/*
	Made by Vladimir Kataev
*/
#include<iostream>
#include<string>
using namespace std;

int main(){
	const int SIZE = 9;
	string planets[SIZE] = { "Mercury", "Venus", "Earth", "Mars",
				"Jupiter", "Saturn", "Uranus",
				"Neptune", "Pluto (a dwarf planet)" };

	cout << "List of the planets:\n";
	for(int a = 0; a < SIZE; a++)
		cout << planets[a] << endl;

	return 0;

}
/*
List of the planets:
Mercury
Venus
Earth
Mars
Jupiter
Saturn
Uranus
Neptune
Pluto (a dwarf planet)
*/
