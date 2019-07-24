#include<stdio.h>
#include<stdlib.h>

int main (int argv, char** argc){
  unsigned int test = 128;
  unsigned int mask  = 1;
  bool firstTrue = false;
  bool didReturn = true;
  for(int i = 0; i < 8; i++){
    if(test & mask ){ // if the 2^mask is one in the number
      if(firstTrue){
	       printf("false \n");
         didReturn = true;
      }
      else{
	       firstTrue = true;
      }
    }
    mask << 1;
  }
  if(!didReturn){printf("true\n");}
  return 0;


}
