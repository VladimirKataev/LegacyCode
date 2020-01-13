#pragma once
#include "DatabaseManager.h"



DatabaseManager::DatabaseManager(std::string path, int size)
{
	table = new HashTable<Car>(size);
	treePrice = new AVLTree<Car>();
	treeHP = new AVLTree<Car>();
	treeYear = new AVLTree<Car>();

	//importList(path, &list);

	std::fstream file;
	std::string tmp;
	try {
		file.open(path);
	}
	catch (...) { std::cout << "Unable to open the file"; }

	Car* pCar;

	while (getline(file, tmp, '\n'))
	{
		pCar = new Car(tmp);
		list.insert(pCar);
	}

	try {
		file.close();
	}
	catch (...) {}

	//end importList

	int max = list.getCount();
	Car* temp;
	for (int i = 0; i < max; i++)
	{
		list.setpPos(i);

		temp = list.getPos();

		table->insert(temp);
		treePrice->traverse(treePrice->getRoot(), 0, 1);
		temp->setComparisonMode(1);  //compare Price
		treePrice->insert(temp);

		//treeHP->traverse(treeHP->getRoot(), 0, 2);
		//temp->setComparisonMode(2);  //compare HP
		//treeHP->insert(temp);

		treeYear->traverse(treeYear->getRoot(), 0, 3);
		temp->setComparisonMode(3);  //compare Year
		treeYear->insert(temp);
		//std::cout << i << std::endl;
	}
}

DatabaseManager::~DatabaseManager()
{
	//exportList(filePath, &list);

	std::ofstream outputFile(filePath);
	if (list.getCount() != 0)
	{
		LinkedNode<Car*>* pCur = list.getPHead();
		std::string tmp;

		while (pCur != nullptr && pCur->getNext() != nullptr)
		{
			if (pCur->getData()->getDriveTrain() == 0)
				tmp = "AWD";
			else if (pCur->getData()->getDriveTrain() == 1)
				tmp = "FWD";
			else if (pCur->getData()->getDriveTrain() == 2)
				tmp = "RWD";

			outputFile << pCur->getData()->getManufacturer() << '|'
				<< pCur->getData()->getModel() << '|'
				<< pCur->getData()->getYear() << '|'
				<< pCur->getData()->getPrice() << '|'
				<< pCur->getData()->getSeats() << '|'
				<< pCur->getData()->getMileage() << '|'
				<< pCur->getData()->getHorsePower() << '|'
				<< tmp << '\n';
			pCur = pCur->getNext();
		}
		if (pCur != nullptr)
			outputFile << pCur->getData()->getManufacturer() << '|'
			<< pCur->getData()->getModel() << '|'
			<< pCur->getData()->getYear() << '|'
			<< pCur->getData()->getPrice() << '|'
			<< pCur->getData()->getSeats() << '|'
			<< pCur->getData()->getMileage() << '|'
			<< pCur->getData()->getHorsePower() << '|'
			<< tmp << std::endl;
	}
	else
		std::cout << "List is empty" << std::endl;

	//end exportList
}


void DatabaseManager::add(Car * c)
{
	table->insert(c);

	list.insertHead(c);

	treePrice->traverse(treePrice->getRoot(), 0, 1);
	c->setComparisonMode(1);  //compare Price
	treePrice->insert(c);

	//c->setComparisonMode(2);  //compare HP
	//treeHP->insert(c);

	treeYear->traverse(treeYear->getRoot(), 0, 3);
	c->setComparisonMode(3);  //compare Year
	treeYear->insert(c);
}

void DatabaseManager::remove(Car * c)
{
	treePrice->remove(c);
	//treeHP->remove(c);
	treeYear->remove(c);

	int index = list.findNode(c);

	table->remove(LinkedNode<Car*>(c));

	list.removeIndex(index);

	delete c;	//delete Car object
}

SinglyLinkedList<Car*>* DatabaseManager::search(Car c, int sortState, int compareMode)
{
	SinglyLinkedList<Car*>* searchResults = new SinglyLinkedList<Car*>(sortState);
	bool searchManufacturer, searchModel, searchYear, searchPrice, searchSeatingCap,
		searchCombMile, searchHorsePower, searchMode;
	searchManufacturer = (c.getManufacturer() == "");
	searchModel = (c.getModel() == "");
	searchYear = (c.getYear() == -1);
	searchPrice = (c.getPrice() == -1);
	searchSeatingCap = (c.getSeats() == -1);
	searchCombMile = (c.getMileage() == -1);
	searchHorsePower = (c.getHorsePower() == -1);
	searchMode = (c.getDriveTrain() == NULLDRIVE);

	Car * check;
	int size = list.getCount();
	for (int i = 0; i < size; i++)
	{
		list.setpPos(i);
		check = list.getPos();
		check->setComparisonMode(compareMode);
		if ((searchManufacturer ? true : c.getManufacturer() == check->getManufacturer()) && (searchModel ? true : c.getModel() == check->getModel())
			&& (searchYear ? true : c.getYear() == check->getYear()) && (searchPrice ? true : c.getPrice() == check->getPrice())
			&& (searchSeatingCap ? true : c.getSeats() == check->getSeats()) && (searchCombMile ? true : c.getMileage() == check->getMileage())
			&& (searchHorsePower ? true : c.getHorsePower() == check->getHorsePower()) && (searchMode ? true : c.getDriveTrain() == check->getDriveTrain()))
		{
			searchResults->insert(check);
		}
	}
	return searchResults;
}

Car DatabaseManager::searchKey(std::string key)
{
	return table->search(key);
}

void DatabaseManager::printIndentedTree(int mode) {
	if (mode == 1) {
		treePrice->printTree(treePrice->getRoot(), 0, 1);
	}
	else if(mode == 2) {
		treeYear->printTree(treeYear->getRoot(), 0, 3);
	}
	else {
		//treeHP->printTree(treeHP->getRoot(), 0);
		std::cout << "Invalid input" << std::endl;
	}
}