#include"Chess.h"
bool King::canMoveTo(Board* where,unsigned int a, unsigned int b){
  //check for OOB
  if(a >7 || b >7){return false;}
  if(a==x && b == y){return false;}
  //if   neitherOBOx        or      OBOy
  if((a-x != 1 && x-a !=1) || (b-y != 1 && y-b != 1)){return false;}
  if(where->isColouredThere(a,b,isWhite)){return false;}
  return true;
}
King::King(unsigned int a, unsigned int b, bool c): Piece(a, b, c){
  x = a;y=b;isWhite=c;isReal = true;
}
void King::render(){
  if(isWhite)printf("K");
  else printf("k");

}
