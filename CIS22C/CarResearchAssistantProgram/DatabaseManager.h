// Written by Antoni Ostrowski
#pragma once

#include <fstream>
#include <string>
#include "AVLTree.h"
#include "Car.h"
#include "HashTable.h"
#include "FileIO.h"

class DatabaseManager
{
private:
	HashTable<Car>* table;
	AVLTree<Car>* treePrice;
	AVLTree<Car>* treeHP;
	AVLTree<Car>* treeYear;
	SinglyLinkedList<Car*> list;

	std::string filePath;
public:
	DatabaseManager(std::string, int);
	~DatabaseManager();

	/*
	PARAM:	Car pointer to add to database
	POST:	Car pointer is added to database
	*/
	void add(Car*);

	/*
	PARAM:	Car pointer to remove from database
	POST:	Car pointer is removed from database
	*/
	void remove(Car*);

	/*
	PARAM:	target Car to search for, sortState of SinglyLinkedList to be returned, comparison mode of Car objects in list
	PRE:	- ignored search parameters in target Car should be set to -1 for int attributes, "" for std::string attributes
			- sortState parameter should be 0 (unsorted), +1 (ascending), or -1 (descending)
			- comparison mode parameter should be 0 (makeModel), 1 (price), 2 (horsepower), 3 (model year)
	RETURN:	SinglyLinkedList sorted by comparison mode attribute in order of sortState containing Car pointers that meet search criteria
	*/
	SinglyLinkedList<Car*>* search(Car,  int, int);

	/*
	PARAM:	hash key of Car to search for
	PRE:	Car must exist in database
	*/
	Car searchKey(std::string);

	void printIndentedTree(int);

};
