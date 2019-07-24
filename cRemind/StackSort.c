#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct StackNode{
  struct StackNode *next;
  int val;
} StackNode;
typedef struct Stack{
  StackNode *top;
} Stack;
int peek(Stack* entry){
  return (entry->top->val);
}
int pop(Stack* entry){
  int toRet = entry->top->val;
  StackNode* toFree = entry->top;
  entry->top = entry->top->next;
  free(toFree);
  return toRet;
}
bool isEmpty(Stack* entry){
  if(entry->top == NULL){
    return true;
  }
  return false;
}
void push(Stack* entry, int newval ){
  StackNode* new = calloc(1,sizeof(StackNode));
  new->val = newval;
  new->next = entry->top;
  entry->top = new;
}
void main(int argc, char** argv){
  Stack* mainStack = malloc(sizeof(Stack));
  StackNode *firstNode = malloc(sizeof(StackNode));
  firstNode->val = 7;
  mainStack->top = firstNode;
  /*
  printf("%d\n",peek(mainStack));
  push(mainStack, 87);
  printf("%d\n",peek(mainStack));
  printf("%d\n", pop(mainStack));
  printf("%d\n", peek(mainStack));
  printf("%d\n", pop(mainStack));
  printf("%b\n");
  printf("\n");
  */
  push(mainStack,8);
  push(mainStack,5);
  push(mainStack,3);
  push(mainStack,9);
  push(mainStack,5);
  push(mainStack,4);
  push(mainStack,5);
  push(mainStack,6);


  //--------------------sorting
  Stack* otherStack = malloc(sizeof(Stack));
  otherStack->top = calloc(sizeof(StackNode),1);
  otherStack->top->val = pop(mainStack);
  int tmp;
  while(!isEmpty(mainStack)){
    tmp = pop(mainStack);
    while(!isEmpty(otherStack) && tmp > peek(otherStack)){
      push(mainStack, pop(otherStack));
    }
    push(otherStack, tmp);
    while(!isEmpty(mainStack) && peek(mainStack) <= peek(otherStack)){
      push(otherStack, pop(mainStack));
    }
  }
  //----------------------/sorting

  // ----------printing
  while(!isEmpty(otherStack)){
    printf("%d\n",pop(otherStack));
  }


}
