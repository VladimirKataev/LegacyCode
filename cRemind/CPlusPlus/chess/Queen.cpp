#include"Chess.h"
bool Queen::canMoveTo(Board* where,unsigned int a, unsigned int b){
  //check for OOB
  if(where->isMoveOutOfBounds(a, b) ||
     where->pieces[a][b]->isWhite == isWhite)
     return false;
  int dirX, dirY;
  if(a > x){dirX = 1;}
  if(a == x){dirX = 0;}
  if(a < x){dirX = -1;}
  if(b > y){dirY = 1;}
  if(b == y){dirY = 0;}
  if(b < y){dirY = -1;}

  for(int tstX = x+dirX, tstY = y+dirY; !where->isMoveOutOfBounds(tstX, tstY); tstX += dirX, tstY += dirY){
    if(tstX == a && tstY == b){return true;}
    if(where->pieces[tstX][tstY]->isReal){return false;}
  }
  return false;
}
void Queen::render(){
  if(isWhite)printf("Q");
  else printf("q");

}
Queen::Queen(unsigned int a, unsigned int b, bool c):Piece(a,b,c) { isReal = true;}
