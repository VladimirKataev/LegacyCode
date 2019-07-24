#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
  struct Node* smallerChild, *largerChild, *parent;
  int value;
} Node;
Node* insertNode(int toAdd, Node* root){  // allocates space for 1 node, insets it in a sorted position as needed
  if(root == NULL){
    made = (Node)* malloc(sizeof(Node));
    made->value = toAdd;
    made->smallerChild = NULL;
    made->largerChild = NULL;
    made->parent = NULL;
    return made;
  }
  if(toAdd > root->value){
    if(toAdd > root->largerChild->value){
      return insertNode(toAdd, root->largerChild);
    }
    Node* tmp = root->largerChild;
    Node* made = (Node)* malloc(sizeof(Node));
    made->parent = root;
    made->largerChild = tmp;
    made->smallerChild = NULL;
    root->largerChild = made;
    made->value = toAdd;
    return made;
  }

  if(toAdd < root->value){
    if(toAdd < root->smallerChild->value){
      return insertNode(toAdd, root->smallerChild);
    }
    Node* tmp = root->smallerChild;
    Node* made = (Node)* malloc(sizeof(Node));
    made->parent = root;
    made->smallerChild = tmp;
    made->largerChild = NULL;
    root->smallerChild = made;
    made->value = toAdd;
    return made;
  }
}

void main(int argc, char** argv){


}
