// Written by Brandon Le
#pragma once
template <class T>
class AVLNode {
private:
	T data;
	int height, balance;
	AVLNode* left, * right;

public:
	/* Constructor for AVL Node
	pre: input - data to be inputed
	post: AVLNode stores the input by using a pointer
	return: none
	*/
	AVLNode(T input);

	/* Destructor
	pre: none
	post: AVLNode is deleted, but since the data pointer is set to nullptr, the object contained is not deleted
	return: none
	*/
	virtual ~AVLNode();

	/* Gets the left child AVLNode
	pre: none
	post: none
	return: left AVLNode
	*/
	AVLNode* getLeft() { return left; }

	/* Gets the right child AVLNode
	pre: none
	post: none
	return: right AVLNode
	*/
	AVLNode* getRight() { return right; }


	/* Sets the left child AVLNode
	pre: node - the AVLNode to be set to the left child AVLNode of this AVLNode
	post: node is the new left child of this AVLNode
	return: none
	*/
	void setLeft(AVLNode<T>* node);

	/* Sets the right child AVLNode
	pre: node - the AVLNode to be set to the right child AVLNode of this AVLNode
	post: node is the new right child of this AVLNode
	return: none
	*/
	void setRight(AVLNode<T>* node);


	/* Gets the data contained by this AVLNode
	pre: none
	post: none
	return: the object pointed by data
	*/
	T getData() { return data; }

	/* Sets the data contained by this AVLNode
	pre: input - data to be inputed
	post: data pointer points to input
	return: none
	*/
	void setData(T input);


	/* Gets the height of the subtree where this AVLNode is the root
	pre: none
	post: none
	return: height
	*/
	int getHeight() const { return height; }

	/* Gets the balance of this AVLNode (negative means height of left subtree is taller and positive means height of right subtree is taller)
	pre: none
	post: none
	return: balance
	*/
	int getBalance() const { return balance; }


	/* Sets the height and the balance
	pre: left - height of the left child
		 right - height of the right child
	post: height is set to the greater of the two heights + 1. Balance is set to the difference between the two heights.
	return: true or false if the height was changed in the call of this function
	*/
	bool setHeightBalance(int left, int right);


	/* Indicates if this AVLNode is balanced (difference in height of the left and right subtrees is less than 2)
	pre: none
	post: none
	return: true or false if this AVLNode is balanced
	*/
	bool isBalanced() const { return abs(balance) < 2; }

	/* Indicates if this AVLNode is left Heavy (balance is negative)
	pre: none
	post: none
	return: true or false if this AVLNode is left Heavy
	*/
	bool isLeftHvy() const { return balance < 0; }

	/* Indicates if this AVLNode is right Heavy (balance is positive)
	pre: none
	post: none
	return: true or false if this AVLNode is right Heavy
	*/
	bool isRightHvy() const { return balance > 0; }

	/* Indicates if this AVLNode is absolutely balanced (balance is 0)
	pre: none
	post: none
	return: true or false is this AVLNode is absolutely balanced
	*/
	bool isAbsBalanced() const { return balance == 0; }

	/* Indicates if this AVLNode is a leaf (has no children)
	pre: none
	post: none
	return: true or false if this AVLNode is a leaf
	*/
	bool isLeaf() const { return height == 1; }

};

template <class T>
AVLNode<T>::AVLNode(T input) {
	data = input;
	height = 1;
	balance = 0;
	left = right = nullptr;
}

template <class T>
AVLNode<T>::~AVLNode() {
	data = nullptr;
}


template <class T>
void AVLNode<T>::setData(T input) {
	data = input;
}

template <class T>
bool AVLNode<T>::setHeightBalance(int left, int right) {
	int hBefore = height;
	if (left > right) height = left + 1;
	else height = right + 1;
	balance = right - left;
	return hBefore != height;
}

template <class T>
void AVLNode<T>::setLeft(AVLNode<T>* node) {
	left = node;
}

template <class T>
void AVLNode<T>::setRight(AVLNode<T>* node) {
	right = node;
}