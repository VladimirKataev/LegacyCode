#pragma once
/*
THIS IS SINGLYLINKEDLIST CLASS. USE FOR CREATE A LINKED LIST TO STORE DIFFERENT TYPE OF DATA.
IT CONTAINS 5 ATTRIBUTES:
INT COUNT;                      // TO COUNT THE ELEMENTS OF LIST
INT SORTSTATE;                  // TO STORE SORT STATE
SORTSTATE:
//	+1 -- ASCENDING ORDER
//	 0 -- UNSORTED
//	-1 -- DESCENDING ORDER

LINKEDNODE<T>* PHEAD;           // POINTER TO THE HEAD
LINKEDNODE<T>* PPOS;			// READ POSITION
LINKEDNODE<T>* PTAIL;			// PINTER TO HE TAIL

//CONSTRACTORS and DESTRACTORS
SINGLYLINKEDLIST();
SINGLYLINKEDLIST(T[], INT, INT);
~SINGLYLINKEDLIST();

// Methods to gets states of the linked list
INT GETCOUNT();		//TOTAL COUNT
INT GETCOUNT(T);	//COUNT OF SPECIFIED DATA-VALUED LINKEDNODES
INT GETSORTSTATE();	//+1 = ASCENDING, 0 = UNORDERED, -1 = DESCENDING

//INSERT METHODS
VOID INSERT(T);				//IF SORTED, INSERT IN CORRECT POSITION; IF UNSORTED, INSERT AT HEAD
VOID INSERTHEAD(T);			//INSERT NEW NODE AT HEAD END
VOID INSERTNODE(T, INT);	//INSERT NEW NODE AT INDEX POSITION
VOID INSERTPOS(T);			//INSERT NEW NODE AFTER NODE AT PPOS, POINT PPOS TO NEW NODE
VOID INSERTTAIL(T);			//INSERT NEW NODE AT TAIL END

//SETTERS
VOID SETHEAD(T);
VOID SETPOS(T);
VOID SETTAIL(T);
VOID SETNODE(T, INT);

//METHOD FOR THE CURRENT POSITION
VOID SETPPOS(INT);	//SET READ POSITION PPOS
INT GETPPOS();		//GET THE INDEX OF PPOS

//GETTER FOR THE NODES
T GETHEAD();
T GETPOS();
T GETTAIL();
T GETNODE(INT);

//SEARCH THE ELEMENT
INT FINDNODE(T);	//RETURN INDEX OF FIRST INSTANCE OF NODE WITH SPECIFIED VALUE

//REMOVE ELEMENT METHOD
VOID REMOVENODE(T);		//REMOVE FIRST INSTANCE OF NODE WITH SPECIFIED VALUE
VOID REMOVEINDEX(INT);	//DELETE NODE AT INDEX
VOID EMPTYLIST();		//DELETE ALL NODES

// CHECK THE LIST IS EMPTY
BOOL ISEMPTY();			//CHECK IF EMPTY

// DISPLAY METHOD
VOID PRINTLIST();	//SEND TO COUT: LIST[0] + '\N' + LIST[1] + '\N' + ... + LIST[N] + '\N'
//FRIEND STD::OSTREAM& OPERATOR<<(STD::OSTREAM&, SINGLYLINKEDLIST);	//INSERT STRING FORM INTO STREAM
*/

#include <string>
#include "LinkedNode.h"

template<typename T>
class SinglyLinkedList
{
	/* NOTES:
	- all indexes assumed to start at pHead (index 0)
	*/
private:
	int count;
	int sortState;
	// sortState:
	//	+1 -- ascending order
	//	 0 -- unsorted
	//	-1 -- descending order

	int pPosIndex;

	LinkedNode<T>* pHead;
	LinkedNode<T>* pPos;	//read position, has bugs for sorted lists
	LinkedNode<T>* pTail;

public:
	SinglyLinkedList();

	/*
	PARAM:	sort state
	PRE:	sort state must be 0 (unsorted), +1 (ascending), or -1 (descending)
	POST:	empty list with indicated sort state is created
	*/
	SinglyLinkedList(int);

	SinglyLinkedList(T[], int, int);
	~SinglyLinkedList();

	int getCount();
	int getCount(T);
	int getSortState();

	LinkedNode<T>* getPHead();

	void insert(T);
	void insertHead(T);
	void insertNode(T, int);
	void insertPos(T);
	void insertTail(T);

	void setHead(T);
	void setPos(T);
	void setTail(T);
	void setNode(T, int);

	void setpPos(int);
	int getpPos();

	T getHead();
	T getPos();
	T getTail();
	T getNode(int);

	int findNode(T);

	void removeNode(T);
	void removeIndex(int);
	void removeHead();
	void removePos();
	void removeTail();
	void emptyList();
	bool isEmpty();
	void printList();
};

//CONSTRACTORS and DESTRACTORS
template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	count = 0;
	sortState = 0;
	pHead = nullptr;
	pPos = nullptr;
	pTail = nullptr;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(int state)
{
	count = 0;
	sortState = state;
	pPosIndex = 0;
	pHead = nullptr;
	pPos = nullptr;
	pTail = nullptr;
}

/*
	PRE: Constract the object if successful
	PAR: data array, size of array, and sort state
	POS: if constraction is successful, data in the array will store in the linked list
*/
template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(T arr[], int size, int sort)
{
	if (sort > 1 || sort < -1)
		throw "invalid sort state";
	count = 0;
	sortState = sort;
	pPosIndex = 0;
	for (int i = 0; i < size; i++)
	{
		this->insertTail(arr[i]);
	}
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	if (pHead != nullptr)
		emptyList();
}

//Methods to gets states of the linked list
template<typename T>
int SinglyLinkedList<T>::getCount() { return count; }

/*
	PRE: This is the getter to return the count of same elements in the list
	POS: Loop the linked list to check if data == the value, if match n ++
	PAR: T value, the value that need to be searched
	RET: The count of the numbers
*/
template<typename T>
int SinglyLinkedList<T>::getCount(T value) {
	LinkedNode<T>* pCur = pHead;
	int n = 0;	//count
	T tmp;
	while (pCur->getNext() != nullptr)
	{
		tmp = pCur->getData();
		if (tmp == value)
		{
			n++;
		}
		pCur = pCur->getNext();
	}
	return n;
}

template<typename T>
int SinglyLinkedList<T>::getSortState() { return sortState; }

template<typename T>
LinkedNode<T>* SinglyLinkedList<T>::getPHead() { return pHead; }

//INSERT METHODS
/*
	PRE: If successful this function will insert one element in to the list
	POS: Check the sorting state, then loop the function to check next element to find the correct position of the element, once it found, set the element to the current postion
	If the the list is not sorted, just insert the element to the first
	PAR: T value, the element that need to be insert
*/
template<typename T>
void SinglyLinkedList<T>::insert(T value)		//FINISH
{
	if (sortState == 1) {
		LinkedNode<T>* pNext = pHead;
		LinkedNode<T>* pCur;
		LinkedNode<T>* pPrev = pHead;
		T tmp;
		while (1) {
			tmp = pNext->getData();
			if (tmp >= value) {
				pCur = new LinkedNode<T>(value);
				pPrev->setNext(pCur);
				pCur->setNext(pNext);
				return;
			}
			else if (pNext->getNext() == nullptr) {
				insertTail(value);
				return;
			}
			pPrev = pNext;
			pNext = pNext->getNext();
		}
	}
	else if (sortState == -1) {
		LinkedNode<T>* pNext = pHead;
		LinkedNode<T>* pCur;
		LinkedNode<T>* pPrev = pHead;
		T tmp;
		while (1) {
			tmp = pNext->getData();
			if (tmp <= value) {
				pCur = new LinkedNode<T>(value);
				pPrev->setNext(pCur);
				pCur->setNext(pNext);
				return;
			}
			else if (pNext->getNext() == nullptr) {
				insertTail(value);
				return;
			}
			pPrev = pNext;
			pNext = pNext->getNext();
		}
	}
	else
		insertHead(value);
}

/*
	PRE: This function will insert one element into the first postion of the Linked list
	POS: check the list is not empty ot empty, insert the element to the postion
	PAR: T value, insert value
*/
template<typename T>
void SinglyLinkedList<T>::insertHead(T value)
{
	if (pHead == nullptr) {		//empty list case
		pHead = new LinkedNode<T>(value);
		pTail = pHead;
		pPos = pHead;
		count++;
	}
	else {
		LinkedNode<T>* pTemp = pHead;
		pHead = new LinkedNode<T>(value);
		pHead->setNext(pTemp);
		count++;
		pPosIndex++;
	}
}

/*
	PRE: If successful this function will insert one element into certain postion
	POS: If index < 0 throw excpetion, otherwise loop the function and find the postion
	PAR: T value, the data need to be insert. Int index, the postion
*/
template<typename T>
void SinglyLinkedList<T>::insertNode(T value, int index)
{
	if (index < 0 || index >= count)
		throw "index out of bounds";
	LinkedNode<T>* pCur = pHead;
	LinkedNode<T>* pPrev = pHead;
	LinkedNode<T>* pNext;
	for (int i = 0; i <= index; i++)
	{
		if (i == index) {
			pNext = pCur;
			pCur = new LinkedNode<T>(value);
			pPrev->setNext(pCur);
			pCur->setNext(pNext);
			count++;
			return;
		}
		if (pCur->getNext() == nullptr)
			throw "list index out of bounds";
		else {
			pPrev = pCur;
			pCur = pPrev->getNext();
		}
	}
	if (index <= pPosIndex)
		pPosIndex++;
}

/*
	PRE: This function will insert one element into the current postion of the Linked list
	POS: check the list is not empty ot empty, insert the element to the postion
	PAR: T value, insert value
*/
template<typename T>
void SinglyLinkedList<T>::insertPos(T value)
{
	if (pHead == nullptr) {		//empty list case
		pHead = new LinkedNode<T>(value);
		pTail = pHead;
		pPos = pHead;
		count++;
	}
	else {
		LinkedNode<T>* pPrev = pPos;
		LinkedNode<T>* pNext = pPos->getNext();
		pPos = new LinkedNode(T);
		pPrev->setNext(pPos);
		pPos->setNext(pNext);
		count++;
	}
}

/*
	PRE: This function will insert one element into the last postion of the Linked list
	POS: check the list is not empty ot empty, insert the element to the postion
	PAR: T value, insert value
*/
template<typename T>
void SinglyLinkedList<T>::insertTail(T value)
{
	if (pHead == nullptr) {		//empty list case
		pHead = new LinkedNode<T>(value);
		pTail = pHead;
		pPos = pHead;
		count++;
	}
	else {
		LinkedNode<T>* pTemp = new LinkedNode<T>(value);
		pTail->setNext(pTemp);
		pTail = pTemp;
		count++;
	}
}

//SETTERS
template<typename T>
void SinglyLinkedList<T>::setHead(T value) { pHead->setData(value); }

template<typename T>
void SinglyLinkedList<T>::setPos(T value) { pPos->setData(value); }

template<typename T>
void SinglyLinkedList<T>::setTail(T value) { pTail->setData(value); }
/*
	PRE: This function will instead the data to one of the node if successful
	POS: If index is invalid throw an exception. Find the postion by index, instead the data
	PAR: T value, the data. Int index, the index
*/
template<typename T>
void SinglyLinkedList<T>::setNode(T value, int index) {
	if (index < 0)
		throw "index cannot be negative value";
	LinkedNode<T>* pCur = pHead;
	for (int i = 0; i <= index; i++)
	{
		if (i == index) {
			pCur->setData(value);
			return;
		}
		if (pCur->getNext() == nullptr)
			throw "list index out of bounds";
		else
			pCur = pCur->getNext();
	}
}

//METHOD FOR THE CURRENT POSITION
/*
	PRE: If sucessful this function will set the postion to a location
	POS: If index is invalid throw an exception. Find the postion by index
	PAR: Int index, the index of postion
*/
template<typename T>
void SinglyLinkedList<T>::setpPos(int index) {
	if (index < 0 || index >= count)
		throw "index out of bounds";
	if (pPosIndex > index) {
		pPosIndex = 0;
		pPos = pHead;
	}
	while (pPosIndex <= index)
	{
		if (pPosIndex == index) {
			return;
		}
		else {
			pPos = pPos->getNext();
			pPosIndex++;
		}
	}
}

/*
	PRE: This function will return the current postion of points
	POS: Find the current postion by pointer
	Return: The index, return -1 if not found
*/
template<typename T>
int SinglyLinkedList<T>::getpPos()
{
	return pPosIndex;
	/*LinkedNode<T>* pCur = pHead;
	for (int i = 0; pCur->getNext() != nullptr; i++, pCur = pCur->getNext()) {
		if (pCur == pPos) {
			return i;
		}
	}
	return -1;
	*/
}

//GETTER FOR THE NODES
/*
	PRE:	list cannot be empty
	RETURN:	data value at head node
*/
template<typename T>
T SinglyLinkedList<T>::getHead() { return pHead->getData(); }

/*
	PRE: pPos pointer must be initialized to point at existing node
	RETURN:	Data value at node pointed to by pPos
*/
template<typename T>
T SinglyLinkedList<T>::getPos() { return pPos->getData(); }

/*
	PRE: For n = index, the list must contain at least n + 1 elements
	POS: Loop the list, find the position by index, then return the data
	RETURN:	The data value of the (n+1)th node
*/
template<typename T>
T SinglyLinkedList<T>::getNode(int index)	//FINISH
{
	LinkedNode<T>* pCur = pHead;
	for (int i = 0; i <= index; i++) {
		if (i == index)
			return pCur->getData();
		if (pCur->getNext() == nullptr)
			throw "list index out of bounds";
		else
			pCur = pCur->getNext();
	}
}

/*
	PRE:	list cannot be empty
	RETURN:	data value of tail node
*/
template<typename T>
T SinglyLinkedList<T>::getTail() { return pTail->getData(); }

//SEARCH THE ELEMENT
/*
	PRE: This function will search the data by T value, if duplicate data exist, it will return first one.
	RETURN: If the list contained value, its position in the list (starting from pHead side of list at index 0) is returned; -1 if value not in list
	PAR: T value, the data want ot searched
*/
template<typename T>
int SinglyLinkedList<T>::findNode(T value)
{
	LinkedNode<T>* pCur = pHead;
	for (int i = 0; pCur->getNext() != nullptr; i++, pCur = pCur->getNext()) {
		T tmp = pCur->getData();
		if (tmp == value)
			return i;
	}
	return -1;
}

//REMOVE ELEMENT METHOD
/*
	POST: If the list contained value, the first instance of it was removed. Can't use for delete first or last element
	PAR: T value, the data need to be removed
*/
template<typename T>
void SinglyLinkedList<T>::removeNode(T value)
{
	LinkedNode<T>* pCur = pHead;
	LinkedNode<T>* pPrev = pHead;
	T tmp;
	while (pCur != nullptr && pCur->getNext() != nullptr) {
		tmp = pCur->getData();
		if (tmp == value) {
			pPrev->setNext(pCur->getNext());
			delete pCur;
			count--;
			return;
		}
		pPrev = pCur;
		pCur = pCur->getNext();
	}
}

/*
	PRE: For n = index, the list must contain at least n + 1 elements
	POST: The (n + 1)th node in the list was removed
	PAR: Int index, the index
*/
template<typename T>
void SinglyLinkedList<T>::removeIndex(int index)
{
	LinkedNode<T>* pCur = pHead;
	LinkedNode<T>* pPrev = pHead;
	for (int i = 0; i <= index && pCur != nullptr && pCur->getNext() != nullptr; i++) {
		if (i == index - 1)
			pPrev = pCur;
		else if (i == index) {
			pPrev->setNext(pCur->getNext());
			delete pCur;
			count--;
			return;
		}
		pCur = pCur->getNext();
	}

}

/*
	PRE: This function will remove the head element of the list. The list must not empty
	POST: Check if empty list. If not set a flag for current pointe position. Removed the head element
		 Set the second element to the head
		 count -- If the pPos is the previous first element, set it to current first element
*/
template<typename T>
void SinglyLinkedList<T>::removeHead()	//FINISH
{
	if (pHead == nullptr)
		return;
	bool flag = false;
	if (pPos = pHead)
		flag = true;
	else if (pHead->getNext() == nullptr) {
		delete pHead;
		count--;
		return;
	}
	LinkedNode<T>* pCur = pHead;
	pHead = pHead->getNext();
	delete pCur;
	count--;
	if (flag)
		pPos = pHead;
}

/*
	PRE: This function will remove the current element if sucessful
	POS: Check what is the current pointer. Remove element if point to first or last element
		If not delete current element. count --
*/
template<typename T>
void SinglyLinkedList<T>::removePos()	//FINISH
{
	if (pPos == nullptr)
		return;
	else if (pPos == pHead) {
		this->removeHead();
		return;
	}
	else if (pPos == pTail) {
		this->removeTail();
		return;
	}
	else if (pPos->getNext() == nullptr) {
		delete pPos;
		count--;
		return;
	}
	LinkedNode<T>* pCur = pPos;
	pPos = pPos->getNext();
	delete pCur;
	count--;
}

/*
	PRE: If successful this function will remove the last element
	POS: Check if it's an empty list. If not delete the last element. Then set the new tail
	count --
*/
template<typename T>
void SinglyLinkedList<T>::removeTail()	//FINISH
{
	if (pTail == nullptr)
		return;
	delete pTail;
	pTail = pHead;
	for (int i = 0; i < count - 1; i++)
	{
		pTail = pTail->getNext();
	}
	pTail->setNext(nullptr);
	count--;
}


/*
	POST: All existing nodes in list were removed
*/
template<typename T>
void SinglyLinkedList<T>::emptyList()
{
	LinkedNode<T>* del = pHead;
	if (pHead != nullptr)
	{
		LinkedNode<T>* tmp = pHead->getNext();

		while (del->getNext() != nullptr)
		{
			tmp = del;
			del = del->getNext();
			delete tmp;
			count--;
		}

	}
	delete del;
	del = nullptr;
	pHead = nullptr;
	pTail = nullptr;
}

// CHECK THE LIST IS EMPTY
/*
	RETURN:	False if no LinkedNodes in list, true otherwise
*/
template<typename T>
bool SinglyLinkedList<T>::isEmpty() { return count == 0; }


// DISPLAY METHOD
/*
	POST: Sends formatted string to cout (List[0] + '\n' + List[1] + '\n' + ... + List[n] + '\n')
*/
template<typename T>
void SinglyLinkedList<T>::printList()
{
	LinkedNode<T>* pCur = pHead;
	while (pCur != nullptr && pCur->getNext() != nullptr)
	{
		std::cout << pCur->getData() << '\n';
		pCur = pCur->getNext();
	}
	if (pCur != nullptr)
		std::cout << pCur->getData() << std::endl;
}
