#include<stdio.h>
#include<stdlib.h>
typedef struct box {
  int height, width, length;
  struct box *next, *prev;
} box;
typedef struct boxStack {
  box *start;
} boxStack;
void enter(boxStack* where, box* what){
  if(where->start == NULL){
    where->start = what;
  }
  else{
    box* tmp = where->start;
    while(tmp->height > what->height && tmp->width > what->width && tmp->length > what->length){
      tmp = tmp->next;
    }
    box* rec = tmp->next->next;
    tmp = what;
    what->next = rec;
  }
}
void main(int argc, char** argv){
  int height, tHeight, bHeight, bWidth, bLength;
  for(int i = 1; i < argc; i = i+3){
    calloc();
  }
}
