// Antoni Ostrowski & HaoXiang Sun
#pragma once
#include "SinglyLinkedList.h"
/*
	THIS IS AN STACKADT CLASS. USE FOR STACK DATA
	COUNTAINS:
	PUBLIC:
	STACKADT();
	STACKADT(T);
	STACKADT(T[], INT);
	VOID PUSH(T);
	VOID POP();
	T STACKTOP();
	BOOL EMPTYSTACK();
	INT STACKCOUNT();
	VOID DISPLAY();
*/

template<typename T>
class StackADT : protected SinglyLinkedList<T>
{
public:
	//Constactors
	StackADT();
	StackADT(T);
	StackADT(T[], int);
	//Destructor
	~StackADT();

	void push(T); // Function to insert one element
	void pop();		// Function to delete one element
	T stackTop();   // Return the Top element

	bool emptyStack(); // check if it's an empty stack
	int stackCount(); // check how many elements in the stack

	void display(); // printout the stack
};

template<typename T>
StackADT<T>::StackADT() : SinglyLinkedList<T>() {}

template<typename T>
StackADT<T>::StackADT(T node) : SinglyLinkedList<T>()
{
	this->insertHead(node);
	this->countI();
}

template<typename T>
StackADT<T>::StackADT(T arr[], int size) : SinglyLinkedList<T>()
{
	for (int i = 0; i < size; i++)
	{
		this->insertHead(arr[i]);
		this->countI();
	}
}
template<typename T>
StackADT<T>::~StackADT()
{
	this->emptyList();
}

template<typename T>
void StackADT<T>::push(T node)
{
	this->insertHead(node);
}

template<typename T>
void StackADT<T>::pop()
{
	if (!this->isEmpty())
		this->removeHead();
}

template<typename T>
T StackADT<T>::stackTop()
{
	if (!this->isEmpty())
		return this->getHead();
}

template<typename T>
bool StackADT<T>::emptyStack()
{
	return this->isEmpty();
}

template<typename T>
int StackADT<T>::stackCount()
{
	return this->getCount();
}


template<typename T>
void StackADT<T>::display()
{
	if (!this->isEmpty())
		this->printList();
	else
		std::cout << "Stack is empty" << std::endl;
}
