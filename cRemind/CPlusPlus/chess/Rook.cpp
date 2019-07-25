#include"Chess.h"
bool Rook::canMoveTo(Board* where,unsigned int a, unsigned int b){  //Hypothetically done
  //check for OOB
  if(a >7 || b >7){return false;}
  if(where->pieces[a][b]->isWhite == isWhite){return false;}
  //if not straight up and right
  if(a != x && b != y){return false;}
  bool stop = false;
  if(a == x && b > y){  //move up
    for(int i = y+1; i <= b; i++){
      if(where->pieces[a][i]->isReal){
        if(i == b){return true;}
        else{return false;}
      }
    }
    return true;
  }

  if(a == x && b < y){  //move down
    for(int i = y-1; i >= b; i--){
      if(where->pieces[a][i]->isReal){
        if(i == b){return true;}
        else{return false;}
      }
    }
    return true;
  }
  if(b == y && a > x){ //move right
    for(int i = x+1; i <= a; i++){
      if(where->pieces[i][b]->isReal){
        if(i == a){return true;}
        else{return false;}
      }
    }
    return true;
  }
  if(b == y && a < x){ //move left
    for(int i = x-1; i >= a; i--){
      if(where->pieces[i][b]->isReal){
        if(i == a){return true;}
        else{return false;}
      }
    }
    return true;
  }

  return false;

}
void Rook::render(){
  if(isWhite)printf("R");
  else printf("r");

}
Rook::Rook(unsigned int a, unsigned int b, bool c):Piece(a,b,c) { isReal = true;}
