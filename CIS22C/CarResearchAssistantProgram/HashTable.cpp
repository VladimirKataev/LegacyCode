// Written by Brandon Le
#include <iostream>
#include <fstream>
#include <string>
#include "Car.h"
#include "HashTable.h"

template <>
HashTable<Car>::HashTable(int sizeHash) {
	table = new LinkedNode<Car*>* [sizeHash]();
	//for (int i = 0; i < sizeHash; i++)
	//	table[i] = nullptr;
	size = sizeHash;
	numEntries = collisions = 0;
}

template <>
HashTable<Car>::~HashTable() {
	delete[] table;
}

template <>
int HashTable<Car>::hash(std::string keystr) {
	int keySize = keystr.size();
	int i = 0;
	int key = 0;
	while (i < keySize) {
		key += (int)keystr[i];
		i++;
	}
	return key % size;
}

template <>
void HashTable<Car>::collisionResolution(int key, LinkedNode<Car*>* insertCar) {
	LinkedNode<Car*>* tmpCar = table[key];
	if (tmpCar == nullptr) { tmpCar = insertCar; }
	else {
		while (tmpCar->getNext() != nullptr) {
			tmpCar = tmpCar->getNext();
			collisions++;
		}
		tmpCar->setNext(insertCar);
	}
}

void HashTable<Car>::insert(Car* car) { this->insert(new LinkedNode<Car*>(car)); }

template <>
void HashTable<Car>::insert(LinkedNode<Car*>* insertCar) {
	numEntries++;
	int key = hash(insertCar->getData()->getKey());
	if (table[key] != nullptr) {
		collisions++;
		collisionResolution(key, insertCar);
	}
	else {
		table[key] = insertCar;
	}
	//printHashTable();
}

template <>
bool HashTable<Car>::remove(LinkedNode<Car*> deleteCar) {
	int keyNum = hash(deleteCar.getData()->getKey());
	LinkedNode<Car*>* tmpNode, * nxtNode;
	tmpNode = table[keyNum];
	if (*(tmpNode->getData()) == *(deleteCar.getData())) {
		if (tmpNode->getNext() != nullptr) table[keyNum] = tmpNode->getNext();
		delete tmpNode;
		numEntries--;
		return true;
	}
	else {
		nxtNode = tmpNode->getNext();
		while (nxtNode != nullptr) {
			if (*(nxtNode->getData()) == *(deleteCar.getData())) {
				if (nxtNode->getNext() != nullptr) {
					tmpNode->setNext(nxtNode->getNext());
				}
				delete nxtNode;
				numEntries--;
				return true;
			}
			tmpNode = nxtNode;
			nxtNode = nxtNode->getNext();
		}
	}
	return false;
}

template <>
Car HashTable<Car>::search(std::string key) {
	int keyNum = hash(key);
	int pos = keyNum;
	while (pos < size) {
		if (table[pos] == nullptr) {
			throw "Invalid Data";
		}
		Car* tmp = table[pos]->getData();
		if (tmp->getKey() == key) {

			Car details(*(table[pos]->getData()));

			return details;
		}
		else {
			LinkedNode<Car*>* pCur = table[pos];
			for (; pCur->getNext() != nullptr && pCur->getNext()->getData()->getKey() != key; pCur = pCur->getNext());
			if (pCur->getNext() == nullptr)
				throw "Invalid Data";
			return *(pCur->getData());
		}
	}
	throw "Invalid Data";
}

template <>
int HashTable<Car>::getSize() const {
	return size;
}

template <>
int HashTable<Car>::getNumEntries() const {
	return numEntries;
}

template <>
void HashTable<Car>::clear() {
	delete[] table;
	table = new LinkedNode<Car*> * [size]();
	numEntries = collisions = 0;
}

template <>
int HashTable<Car>::getCollisions() const {
	return collisions;
}
/*
template<>
void HashTable<Car>::printHashTable() {
	for (int i = 0; i < size; i++) {
		if (table[i] == nullptr) {
			std::cout << "nullptr" << std::endl;
		}
		else {
			std::cout << *(table[i]->getData()) << std::endl;
		}
	}
}
*/