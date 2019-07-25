#include<stdio.h>
#include<stdlib.h>

int main (int argv, char** argc){
  unsigned int test = 4294967296;
  unsigned int mask  = 1;
  unsigned int ans =0 ;
  bool firstTrue = false;
  bool didReturn = false;
  for(int i = 0; i < sizeof(int)*8; i++){ // limit at 2^bytes
    ans = test & mask;
    printf("%d \t %d \n", ans, mask);
    if(ans !=0){ // if the 2^mask is one in the number
      //printf("matchMade\n");
      if(firstTrue){
	       printf("false \n");
         didReturn = true;
         break;
      }
      else{
	       firstTrue = true;
      //   printf("firstCollision\n");
      }
    }
    mask = mask << 1;
  }
  if(!didReturn){printf("true\n");}
  return 0;


}
