#include"Chess.h"
bool Bishop::canMoveTo(Board* where,unsigned int a, unsigned int b){
  //check for OOB
  if(a >7 || b >7){return false;}
  if(a==x || b == y){return false;}
  if(where->pieces[a][b]->isWhite == isWhite){return false;}
  int dirX, dirY,tstX,tstY;
  if(a > x){dirX = 1;}
  if(a < x){dirX = -1;}
  if(b > y){dirY = 1;}
  if(b < y){dirY = -1;}
  tstX = x;
  tstY = y;
  while(tstY < 7 && tstY >0 && tstX > 0 && tstX <7){
    tstX += dirX;
    tstY += dirY;
    if(!where->pieces[tstX][tstY]->isReal && tstX == a && tstY == b){ //if we got to where we need to be
      return true;
    }
    if(where->pieces[tstX][tstY]->isReal && where->pieces[tstX][tstY]->isWhite != isWhite){ // if we got blocked by opposite
      if(tstX == a && tstY == b){return true;}
      else{return false;}
    }
    if(a == tstX && b == tstY){return true;}
  }
  return false;
}
Bishop::Bishop(unsigned int a, unsigned int b, bool c): Piece(a, b, c){
  isReal = true;
}
void Bishop::render(){
  if(isWhite)printf("B");
  else printf("b");

}
