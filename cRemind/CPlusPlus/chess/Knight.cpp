#include"Chess.h"
bool Knight::canMoveTo(Board* where,unsigned int a, unsigned int b){    //Hypothetically done
  //check for OOB
  if(a >7 || b >7){return false;}
  if(where->pieces[a][b]->isWhite == isWhite){return false;}
  if(a-x == 1 || x-a == 1){
    if(b-y == 2 || y-b == 2){
      return true;
    }
  }
  if(a-x == 2 || x-a == 2){
    if(b-y == 1 || y-b == 1){
      return true;
    }
  }
  return false;
}
void Knight::render(){
  if(isWhite)printf("N");
  else printf("n");

}
Knight::Knight(unsigned int a, unsigned int b, bool c) : Piece(a, b, c) { isReal = true;}
