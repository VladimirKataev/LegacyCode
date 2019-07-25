#include"Chess.h"
bool Board::isMoveOutOfBounds(unsigned int x, unsigned int y){
	if(y >= 8 || x >= 8){return false;}
	return true;
};
int Board::coordinateToInteger(char* coordinate){
	char l = coordinate[0];
	int w = (int)l -65;
	int h = ((int)coordinate[1] - 48)* 8;
	return h+w;
};
void Board::addPiece(Piece* toAdd){
	printf("Added Piece to %d, %d\n", toAdd->x, toAdd->y);
	pieces[toAdd->x][toAdd->y] = toAdd;

}
void Board::setValues(){
	for(int a = 0; a < 8; a++){
		for(int b =0; b < 8; b++){
			Piece* newPiece = new Piece(a, b, false);
			pieces[a][b] = newPiece;
		}

	}
}

Piece* Board::returnPointer(unsigned int a, unsigned int b){
	return pieces[a][b];
}
bool Board::isColouredThere(unsigned int a, unsigned int b, bool white){
	if(pieces[a][b]->isReal && pieces[a][b]->isWhite == white){return true;}
	return false;
}
void Board::render(){
	for(int a = 7; a >=0; a--){
		for(int b = 0; b <8 ; b++){
			pieces[b][a]->render();
		}
		printf("|%d\n",a);
	}
	printf("--------\n01234567\n");
}

bool Board::isInCheck(King* toCheck){
	for(int a = 0; a < 8; a++){
		for(int b = 0; b < 8; b++){
			if(pieces[a][b]->isReal && pieces[a][b]->canMoveTo(this,toCheck->x,toCheck->y)){return true;}
		}
	}
	return false;
}
