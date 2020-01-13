// Antoni Ostrowski & HaoXiang Sun
#pragma once
/*
THIS IS A LINKED NODE CLASS
IT HAS TWO ATTRIBUTES:
T DATA;
LINKEDNODE* PNEXT;
METHOD:
LINKEDNODE(T);                 // DEFAULT CONSTRACTOR
T GETDATA();                   // GETTER FOR DATA
LINKEDNODE* GETNEXT();         // GETTER FOR POINTER TO NEXT DATA
VOID SETDATA(T);               // SETTER FOR DATA
VOID SETNEXT(LINKEDNODE*);     // SETTER FOR POINTER TO NEXT DATA
*/

template<typename T>
class LinkedNode
{
private:
	T data;
	LinkedNode* pNext = nullptr;

public:
	LinkedNode(T);

	LinkedNode& operator= (const LinkedNode& right);

	T getData() const;
	LinkedNode* getNext() const;

	void setData(T);
	void setNext(LinkedNode*);
};
// DEFAULT CONSTRACTOR
template<typename T>
LinkedNode<T>::LinkedNode(T thing) { data = thing; }

// GETTER FOR DATA
template<typename T>
T LinkedNode<T>::getData() const { return data; }

// GETTER FOR POINTER TO NEXT DATA
template<typename T>
LinkedNode<T>* LinkedNode<T>::getNext() const {return pNext; }

// SETTER FOR DATA
template<typename T>
void LinkedNode<T>::setData(T thing) { data = thing; }

// SETTER FOR POINTER TO NEXT DATA
template<typename T>
void LinkedNode<T>::setNext(LinkedNode* ptr) { pNext = ptr; }

template<typename T>
LinkedNode<T>& LinkedNode<T>::operator= (const LinkedNode<T>& right) {
	setData(right.getData());
	setNext(right.getNext());
	return *this;
}
