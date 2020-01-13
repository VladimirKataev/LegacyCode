// Written by Brandon Le
#pragma once
#include <iostream>
#include <string>
#include "AVLNode.h"
#include "QueueADT.h"
#include "StackADT.h"
template <class T>
class AVLTree {
private:
	AVLNode<T*>* root;
	int count, compMode;

	/* Rotates a subtree left to correct a right imbalance
	pre: node - the AVLNode where the left rotation is to occur
	post:
	return: none
	*/
	void rotateLeft(AVLNode<T*>* node);

	/* Rotates a subtree right to correct a left imbalance
	pre: node - the AVLNode where the right rotation is to occur
	post:
	return: none
	*/
	void rotateRight(AVLNode<T*>* node);

	/* The original AVLNode's parent changes to the parent of the replacement AVLnode
	pre: original - the original child AVLNode
		 replace - the new child AVLNode
	post: the parent of the original becomes the parent of the replacement (original is no longer the child of parent)
	return: none
	*/
	void replaceChild(AVLNode<T*>* original, AVLNode<T*>* replace);

public:

	/* Constructor
	pre: none
	post: AVLTree is created and root is set to nullptr
	return: none
	*/
	AVLTree();

	/* Gets the root AVLNode of the tree
	pre: none
	post: none
	return: root
	*/
	AVLNode<T*>* getRoot() { return root; }

	/* Inserts an AVLNode with specified data value into tree
	param:	data of node to be inserted
	post:	node with specified data is inserted into the tree and the necessary rotations are made to keep the tree balanced
	*/
	void insert(T*);

	/* Inserts an AVLNode into the tree
	pre: node - pointer to an AVLNode to be inserted
	post: node is inserted into the tree and the necessary rotations are made to keep the tree balanced
	return: none
	*/
	void insert(AVLNode<T*>* node);

	/* Delete an AVLNode from the tree
	pre: node - an AVLNode containing the data of a similar node in the tree to be deleted
	post: the AVLNode in the tree with similar data as node is deleted and the necessary rotations are made to keep the tree balanced
	return: none
	*/
	bool remove(AVLNode<T*> node);

	/* Traverses the tree
	pre: start - the root of a tree or subtree to traverse
		 order - the selected order to traverse (-1: preorder, 0: inorder, 1: postorder, any other number: breadth-first)
		 comp - comparison mode for Car
	post: all Cars will be set to comparsion mode comp
	return: a string with all the data in the tree in the order selected
	*/
	std::string traverse(AVLNode<T*>* start, int order, int comp);

	/* Binary Search
	pre: searchCopy - an AVLNode with data
	post: none
	return: pointer to an AVLNode in the tree with the same data as search copy
	*/
	AVLNode<T*>* binarySearch(AVLNode<T*> searchCopy);

	/* Prints the entire AVL tree
	pre: start - pointer to a node of the tree
		 depth - the depth of the start node (root node depth = 0, child of root = 1, child of child = 2, etc..)
		 comp - comparison mode of Car
	post: Entire tree is printed to the command line
	return: none
	*/
	void printTree(AVLNode<T*>* start, int depth, int comp);

	/* Returns the number of AVLNodes in the tree
	pre: none
	post: none
	return: count
	*/
	int getCount() const { return count; }
};

template <class T>
AVLTree<T>::AVLTree() {
	root = nullptr;
	count = 0;
	//compMode = comp;
}

template <class T>
void AVLTree<T>::rotateLeft(AVLNode<T*>* node) {
	AVLNode<T*>* nxtRoot = node->getRight();

	if (nxtRoot->isRightHvy() || nxtRoot->isLeaf() || nxtRoot->isAbsBalanced()) {

		int lvlLeft, lvlRight;
		if (node->getLeft() != nullptr) lvlLeft = node->getLeft()->getHeight();
		else lvlLeft = 0;

		if (nxtRoot->getLeft() != nullptr) {
			node->setRight(nxtRoot->getLeft());
			lvlRight = node->getRight()->getHeight();
		}
		else {
			node->setRight(nullptr);
			lvlRight = 0;
		}
		node->setHeightBalance(lvlLeft, lvlRight);

		nxtRoot->setLeft(node);

		lvlLeft = node->getHeight();
		if (nxtRoot->getRight() != nullptr) lvlRight = nxtRoot->getRight()->getHeight();
		else lvlRight = 0;

		nxtRoot->setHeightBalance(lvlLeft, lvlRight);

		if (node != root) {
			replaceChild(node, nxtRoot);
		}
		else {
			root = nxtRoot;
		}

	}
	else {
		rotateRight(nxtRoot);
		rotateLeft(node);
	}
}

template <class T>
void AVLTree<T>::rotateRight(AVLNode<T*>* node) {
	AVLNode<T*>* nxtRoot = node->getLeft();

	if (nxtRoot->isLeftHvy() || nxtRoot->isLeaf() || nxtRoot->isAbsBalanced()) {
		int lvlLeft, lvlRight;
		if (node->getRight() != nullptr) lvlRight = node->getRight()->getHeight();
		else lvlRight = 0;

		if (nxtRoot->getRight() != nullptr) {
			node->setLeft(nxtRoot->getRight());
			lvlLeft = node->getLeft()->getHeight();
		}
		else {
			node->setLeft(nullptr);
			lvlLeft = 0;
		}
		node->setHeightBalance(lvlLeft, lvlRight);

		nxtRoot->setRight(node);
		lvlRight = node->getHeight();
		if (nxtRoot->getLeft() != nullptr) lvlLeft = nxtRoot->getLeft()->getHeight();
		else lvlLeft = 0;
		nxtRoot->setHeightBalance(lvlLeft, lvlRight);

		if (node != root) {
			replaceChild(node, nxtRoot);
		}
		else {
			root = nxtRoot;
		}
	}
	else {
		rotateLeft(nxtRoot);
		rotateRight(node);
	}
}

template <class T>
void AVLTree<T>::replaceChild(AVLNode<T*>* original, AVLNode<T*>* replace) {
	AVLNode<T*>* tmp = root;
	while (tmp->getLeft() != original && tmp->getRight() != original) {
		
		if (*(original->getData()) < *(tmp->getData())) {
			tmp = tmp->getLeft();
		}
		else {
			tmp = tmp->getRight();
		}
	}
	if (tmp->getRight() == original) {
		tmp->setRight(replace);
	}
	else {
		tmp->setLeft(replace);
	}
}

template <class T>
void AVLTree<T>::insert(T* data) { insert(new AVLNode<T*>(data)); }

template <class T>
void AVLTree<T>::insert(AVLNode<T*>* node) {
	count++;
	if (root == nullptr) {
		root = node;
	}
	else {
		StackADT<AVLNode<T*>*> pathway;
		AVLNode<T*>* tmpNode, * nxtNode;
		tmpNode = root;
		nxtNode = tmpNode;
		while (nxtNode != nullptr) {
			tmpNode = nxtNode;
			pathway.push(tmpNode);
			if (*(node->getData()) < *(tmpNode->getData())) {
				nxtNode = tmpNode->getLeft();
			}
			else {
				nxtNode = tmpNode->getRight();
			}
		}

		if (*(node->getData()) < *(tmpNode->getData())) {
			tmpNode->setLeft(node);
		}
		else {
			tmpNode->setRight(node);
		}

		bool rotated = false;
		bool heightUpdate = true;
		int lvlLeft, lvlRight;

		while (!pathway.emptyStack()) {
			lvlLeft = lvlRight = 0;
			tmpNode = pathway.stackTop();
			if (heightUpdate) {
				nxtNode = tmpNode->getLeft();
				if (nxtNode != nullptr) lvlLeft = nxtNode->getHeight();
				nxtNode = tmpNode->getRight();
				if (nxtNode != nullptr) lvlRight = nxtNode->getHeight();

				heightUpdate = tmpNode->setHeightBalance(lvlLeft, lvlRight);

				if (!rotated && !tmpNode->isBalanced()) {
					if (tmpNode->isLeftHvy()) {
						rotateRight(tmpNode);
					}
					else {
						rotateLeft(tmpNode);
					}
					rotated = true;
				}
			}
			pathway.pop();
		}
	}
}



template <class T>
bool AVLTree<T>::remove(AVLNode<T*> node) {
	StackADT<AVLNode<T*>*> pathway;

	int lvlLeft, lvlRight;
	AVLNode<T*>* tmpNode, * del, * nxtNode;

	tmpNode = root;

	while (*(tmpNode->getData()) != *(node.getData()) && tmpNode != nullptr) {
		pathway.push(tmpNode);

		if (*(node.getData()) < *(tmpNode->getData())) {
			tmpNode = tmpNode->getLeft();
		}
		else {
			tmpNode = tmpNode->getRight();
		}
	}
	del = tmpNode;
	pathway.push(del);

	if (del == nullptr) {
		while (!pathway.emptyStack()) pathway.pop();
		return false;
	}
	else if (del->isLeaf()) {
		pathway.pop();
		if (!pathway.emptyStack()) {
			tmpNode = pathway.stackTop();
			if (tmpNode->getLeft() == del) {
				tmpNode->setLeft(nullptr);
			}
			else {
				tmpNode->setRight(nullptr);
			}
		}
	}
	else {
		//find inOrder Predecessor
		bool right = false;
		if (tmpNode->getLeft() != nullptr) {
			tmpNode = tmpNode->getLeft();

			while (tmpNode->getRight() != nullptr) {
				pathway.push(tmpNode);
				tmpNode = tmpNode->getRight();
				right = true;
			}
		}
		else {
			// If there is no inorder predecessor find inorder successor
			right = true;
			tmpNode = tmpNode->getRight();
			if (tmpNode->getLeft() != nullptr) {
				pathway.push(tmpNode);
				tmpNode = tmpNode->getLeft();
				right = false;
			}
		}
		// Swap InOrder Predecessor and Delete Node
		del->setData(tmpNode->getData());
		del = tmpNode;

		tmpNode = pathway.stackTop();
		if (right) tmpNode->setRight(nullptr);
		else tmpNode->setLeft(nullptr);
	}

	while (!pathway.emptyStack()) {
		lvlLeft = lvlRight = 0;
		tmpNode = pathway.stackTop();

		nxtNode = tmpNode->getLeft();
		if (nxtNode != nullptr) lvlLeft = nxtNode->getHeight();
		nxtNode = tmpNode->getRight();
		if (nxtNode != nullptr) lvlRight = nxtNode->getHeight();

		tmpNode->setHeightBalance(lvlLeft, lvlRight);

		if (!tmpNode->isBalanced()) {
			if (tmpNode->isLeftHvy()) {
				rotateRight(tmpNode);
			}
			else {
				rotateLeft(tmpNode);
			}
		}
		pathway.pop();
	}
	delete del;
	count--;
	return true;
}

template <class T>
std::string AVLTree<T>::traverse(AVLNode<T*>* start, int mode, int comp) {
	
	if (start == nullptr) {
		return "";
	}
	start->getData()->setComparisonMode(comp);
	if (mode == -1) {
		
		return "" + *(start->getData()) + "\n " + traverse(start->getLeft(), mode, comp) + traverse(start->getRight(), mode, comp);
	}
	else if (mode == 0) {
		return "" + traverse(start->getLeft(), mode, comp) + " " + *(start->getData()) +"\n" + traverse(start->getRight(), mode, comp);
	}
	else if (mode == 1) {
		return "" + traverse(start->getLeft(), mode, comp) + traverse(start->getRight(), mode, comp) + "\n " + *(start->getData());
	}
	else {
		std::string ans = "";
		QueueADT<AVLNode<T*>*> toSearch;
		toSearch.enqueue(start);
		AVLNode<T*>* nodeOut;
		while (!toSearch.emptyQueue()) {
			nodeOut = toSearch.queueFront();
			ans = ans + *(nodeOut->getData()) + " ";

			AVLNode<T*>* left = nodeOut->getLeft();
			AVLNode<T*>* right = nodeOut->getRight();

			if (left != nullptr) toSearch.enqueue(left);
			if (right != nullptr) toSearch.enqueue(right);
			toSearch.dequeue();
		}
		return ans;
	}

}

template <class T>
AVLNode<T*>* AVLTree<T>::binarySearch(AVLNode<T*> searchCopy) {
	AVLNode<T>* tmpNode = root;
	if (*(searchCopy.getData()) == *(tmpNode->getData())) {
		return tmpNode;
	}
	else {
		if (*(searchCopy.getData()) < *(tmpNode->getData())) {
			tmpNode = tmpNode->getLeft();
		}
		else {
			tmpNode = tmpNode->getRight();
		}
	}
}

template <class T>
void AVLTree<T>::printTree(AVLNode<T*> * start, int depth, int comp) {
	std::string space = "";
	start->getData()->setComparisonMode(comp);
	for (int i = 0; i < depth; i++) {
		space += "          ";
	}
	std::cout << space << "N " + *(start->getData()) << std::endl;
	if (start->getLeft() != nullptr) {
		printTree(start->getLeft(), depth + 1, comp);
	}
	if (start->getRight() != nullptr) {
		printTree(start->getRight(), depth + 1, comp);
	}
	







	/*
	std::string data = std::to_string(start->getData());
	int size = data.size();
	for (int i = size; i < 3; i++) {
		data = " " + data;
	}


	std::cout << "{" + data + "}";
	if (!start->isLeaf()) {
		std::cout << "--+";
		if (start->getLeft() != nullptr) {
			std::cout << "--";
			printTree(start->getLeft(), depth+1);
		}
		else if (start->getRight() != nullptr) {
			for (int i = 0; i < depth; i++) {
				std::cout << "     ";
				std::cout << "   |";
				for (int space = 0; space < 2 (40); space++) {
					std::cout << " ";
				}
		}

		printTree();
		}
	}
	*/


}