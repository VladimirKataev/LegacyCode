#include"Chess.h"
bool Pawn::canMoveTo(Board* where,unsigned int a, unsigned int b){  //Hypothetically done
  //check for OOB
  if(a >7 || b >7){return false;}
  //          no stepping on real pieces of our colour
  if(where->pieces[a][b]->isReal && (where->pieces[a][b]->isWhite == isWhite)){return false;}
  //          if nothing there, make sure is straight in right direction
  if(where->pieces[a][b]->isReal == false && a==x){
      //whites go up 1
    if(isWhite && b-y == 1){return true;}
    if(!isWhite && y-b == 1){return true;}
  }
  //now for eating logic, guaranteed something, guaranteed not of our colour
  if(a-x != 1 && x-a !=1){return false;}
  //now guaranteed one right-left
  if(isWhite && b-y == 1){return true;}
  if(!isWhite && y-b ==1){return true;}
  return false;

}
void Pawn::setValues(unsigned int a, unsigned int b, bool col){
  x = a;
  y = b;
  isWhite = col;
  isReal = true;

}
void Pawn::render(){
  if(isWhite){printf("P");}
  else{printf("p");}

}

Pawn::Pawn(unsigned int a, unsigned int b, bool c) : Piece(a, b, c) { isReal = true;}
