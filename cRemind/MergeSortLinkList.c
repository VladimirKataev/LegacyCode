#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
  struct Node* nxt;
  int val;
} Node;
Node* findHalfBetween(Node* start);
void printWholeList(Node* start);
Node* merge(Node* listOne, Node* listTwo);
Node* MergeSort(Node* start);

int main(int argc, char** argv){
  Node *start = NULL;  //ptr to first node
  Node **curNode = &start;          // will work with, ptr to current working
  for(int i = 1; i < argc; i++){
      *curNode = calloc(sizeof(Node), 1);
      (*curNode)->val = atoi(argv[i]);
      curNode = &(*curNode)->nxt;
  }
  printf("%d \n", findHalfBetween(start)->val);
  printWholeList(start);

  start = MergeSort(start);

  printf("\n");
  printWholeList(start);

  while(start != NULL){
    Node *tmp = start->nxt;
    free(start);
    start = tmp;
  }

  printf("\n");

  return 0;
}

void insertNode(Node* preNode,Node* add){
  Node* tmp = preNode->nxt;
  preNode->nxt = add;
  add->nxt = tmp;
}

void printWholeList(Node* start){
  Node* tmp = start;
  while(tmp != NULL){
    printf("%d ", tmp->val);
    tmp = tmp->nxt;
  }
}

Node* findHalfBetween(Node* start){
  Node* rabbit = start;
  Node* turtle = start;
  while(rabbit->nxt != NULL && rabbit->nxt->nxt != NULL){
    rabbit = rabbit->nxt->nxt;
    turtle = turtle->nxt;
  }
  return turtle;
}

Node* MergeSort(Node* start){
  Node* half = findHalfBetween(start);
  Node* afterhalf = half->nxt;
  half->nxt = NULL;
  return merge(start, afterhalf);
}

Node* merge(Node* listOne, Node* listTwo){
  if(listOne == NULL)      return listTwo;
  if(listTwo == NULL)      return listOne;
    Node* L = MergeSort(listOne);
    Node* R = MergeSort(listTwo);
    Node* ret;

    if(L->val < R->val){ ret = L; L=L->nxt; }
    else{ ret = R; R=R->nxt; }
    Node* retCur = ret;

    while(L != NULL || R != NULL){
      //situation to add from right
      if(R != NULL && (L == NULL || R->val < L->val)){
        retCur->nxt = R;
        retCur = retCur->nxt;
        R = R->nxt;
        retCur->nxt = NULL;
      }
      // situation to add from left
      else{
        retCur->nxt = L;
        retCur = retCur->nxt;
        L = L->nxt;
        retCur->nxt = NULL;
      }
    }
    printf("\nM="); printWholeList(ret);
    return ret;
}
