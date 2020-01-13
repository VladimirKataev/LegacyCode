// Written by HaoXiang Sun
#pragma once
#include "SinglyLinkedList.h"
#include "Car.h"
#include <fstream>


template <class Car>
SinglyLinkedList<Car*>* importList(std::string path, SinglyLinkedList<Car*>* list)
{
	std::fstream file;
	std::string tmp;
	try {
		file.open(path);
	}
	catch (...) { std::cout << "Unable to open the file"; }

	while (getline(file, tmp, '\n'))
	{
		list->insert(&Car(tmp));
	}

	try {
		file.close();
	}
	catch (...) {}

	return list;
}

template <class Car>
void exportList(std::string path, SinglyLinkedList<Car*>* list)
{
	std::ofstream outputFile(path);
	if (list->getCount() != 0)
	{
		LinkedNode<Car*>* pCur = list->getPHead();
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
}


