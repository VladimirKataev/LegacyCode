#include"Chess.h"
void Piece::setValues(unsigned int a, unsigned int b){
  x = a;
  y = b;
  isReal = false;

};
Piece::Piece(unsigned int a,unsigned int b, bool c){
  x=a;y=b;isWhite=c;
}
bool Piece::canMoveTo(Board* toCheck, unsigned int a, unsigned int b){
  return false;
};
void Piece::render(){
  printf(" ");
}
