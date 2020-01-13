// Antoni Ostrowski & HaoXiang Sun
#pragma once
#include "SinglyLinkedList.h"
/*
	THIS IS AN QUEUEADT CLASS. USE FOR Queue DATA
	COUNTAINS:
	PUBLIC:
	QueueADT();
	QueueADT(T);
	QueueADT(T[], INT);
	VOID ENQUEUE(T);
	VOID DEQUEUE();
	T QUEUEFRONT();
	T QUEUEREAR();
	BOOL EMPTYQUEUE();
	INT QUEUECOUNT();
	VOID DISPLAY();
*/

template<typename T>
class QueueADT : protected SinglyLinkedList<T>
{
public:
	//Constactors
	QueueADT();
	QueueADT(T);
	QueueADT(T[], int);
	//Destructor
	~QueueADT();

	void enqueue(T); // Function to insert one element
	void dequeue();		// Function to delete one element
	T queueFront();   // Return the Top element
	T queueRear();		// Freturn the last element
	bool emptyQueue(); // check if it's an empty stack
	int queueCount(); // check how many elements in the stack

	void display(); // printout the stack
};

template<typename T>
QueueADT<T>::QueueADT() : SinglyLinkedList<T>() {}

template<typename T>
QueueADT<T>::QueueADT(T node) : SinglyLinkedList<T>()
{
	this->insertTail(node);
	this->countI();
}

template<typename T>
QueueADT<T>::QueueADT(T arr[], int size) : SinglyLinkedList<T>()
{
	for (int i = 0; i < size; i++)
	{
		this->insertTail(arr[i]);
		this->countI();
	}
}
template<typename T>
QueueADT<T>::~QueueADT()
{
	this->emptyList();
}

template<typename T>
void QueueADT<T>::enqueue(T node)
{
	this->insertTail(node);
}

template<typename T>
void QueueADT<T>::dequeue()
{
	if (!this->isEmpty())
		this->removeHead();
}

template<typename T>
T QueueADT<T>::queueFront()
{
	if (!this->isEmpty())
		return this->getHead();
}

template<typename T>
T QueueADT<T>::queueRear()
{
	if (!this->isEmpty())
		return this->getTail();
}

template<typename T>
bool QueueADT<T>::emptyQueue()
{
	return this->isEmpty();
}

template<typename T>
int QueueADT<T>::queueCount()
{
	return this->getCount();
}


template<typename T>
void QueueADT<T>::display()
{
	if (!this->isEmpty())
		this->printList();
	else
		std::cout << "Stack is empty" << std::endl;
}
