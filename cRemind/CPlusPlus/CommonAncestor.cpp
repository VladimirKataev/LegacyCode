#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef struct Node{
  struct Node* l, *r;
  int id;
} Node;
void addNode(Node* parent, Node* child){
  if(parent->l == NULL){ parent->l == child;}
  else if(parent->r == NULL){parent->r == child;}
  else{addNode(parent->l, child);}
}

typedef struct Triple {
    int id, l, r;
    struct Triple *next;
} Triple;

static Node *makeNode(Triple *data, int id) {
    if(id >= 0)
        for(Triple *line=data; line; line=line->next)
            if(line->id == id) {
                Node *n = (Node*)malloc(sizeof(Node));
                n->id = id;
                n->l = makeNode(data, line->l);
                n->r = makeNode(data, line->r);
                return n;
            }
    return NULL;
}
bool isBelow(Node* parent, Node* target){
  if(target == parent){
    return true;
  }
  if(parent == NULL){
    return false;
  }
  else if(parent->l == NULL && parent->r == NULL){
    return false;
  }
  else{
    return (isBelow(parent->l, target) || isBelow(parent->r, target));
  }
}
Node *readCsv(FILE *f) {
    Triple *ptr, tmp;

    while(!feof(f))
        if(3 == fscanf(f, "%d,%d,%d", &tmp.id, &tmp.l, &tmp.r)) {
            tmp.next = ptr;
            ptr = (Triple*)malloc(sizeof(tmp));
            *ptr = tmp;
        }

    Node *ret = makeNode(ptr, ptr->id);

    while(ptr) {
        tmp = *ptr;
        free(ptr);
        ptr = tmp.next;
    }

    return ret;
}
void freeTree(Node* hed){
  if(hed->l != NULL){
    freeTree(hed->l);
  }
  if(hed->r != NULL){
    freeTree(hed->r);
  }
  free(hed);
}
Node* findIdPointer(int id1, Node* top){
  if(top == NULL){
    return NULL;
  }
  if(top->id == id1){
    return top;
  }

  if(findIdPointer(id1, top->l) == NULL){
    return findIdPointer(id1, top->r);
  }
  else{
    return findIdPointer(id1, top->l);
  }
}
Node* commonAncestor(Node* a, Node* b, Node* top){
  if(a == b){ //obvious
    printf("Fuq U");
    return a;
  }
  if(a == top && isBelow(top , b)){   //he my grandkid
    return a;
  }
  if(b == top && isBelow(top, a)){    //he my grandkid
    return b;
  }
  if(isBelow(top, a) && isBelow(top, b)){ // we are a common Ancestor
    if(isBelow(top->l, a)  && isBelow(top->l, b)){  //is lkid common ancestor?
      return (commonAncestor(a, b, top->l));
    }
    if(isBelow(top->r, a)  && isBelow(top->r, b)){  //is rkid common ancestor?
      return (commonAncestor(a, b, top->r));
    }
    else{                                           // I have to be common ancestor
      return top;
    }
  }
}
int main(int argc, char** argv){
  // enter Node system
  string parseLine;
  //use scanf
  FILE *f = fopen("66.csv", "r");
  Node* treeRoot = readCsv(f);
  if(argc == 3){
    printf("%p \t %p\n", findIdPointer(atoi(argv[1]),treeRoot), findIdPointer(atoi(argv[2]), treeRoot));
    printf("%d",commonAncestor(findIdPointer(atoi(argv[1]),treeRoot), findIdPointer(atoi(argv[2]), treeRoot), treeRoot)->id);



    printf("\n");

  }
  freeTree(treeRoot);
  fclose(f);
  return 1;
}
