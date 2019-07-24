#include<stdlib.h>
#include<stdio.h>
class Box{
  int height, width, length;
  BoxList canStackBelow;
} box;
class BoxListNode{
  Box* obj;
  BoxListNode* next;
} BoxListNode;
class BoxList{
    BoxListNode* first;
    BoxListNode* last;
    int n;
  public:
    BoxListNode* first();
    BoxListNode* nth(int a);
    void add(Box* entry);
} BoxList;
void BoxList::add(Box* entry){
  BoxListNode* made = calloc(sizeof(BoxListNode), 1);
  if(n == 0){
    first = made;
  }
  made->obj = entry;
  last->next = made;
  last = made;
  n++;
}
BoxListNode* BoxList::nth(int a){
  BoxListNode* b = first;
  for(int i = 0; i < a; i++){
    b = b->next;
  }
  return b;
}
