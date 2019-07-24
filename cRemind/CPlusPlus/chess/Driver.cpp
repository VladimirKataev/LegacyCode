#include<stdlib.h>
#include"Chess.h"

int main(int argc, char** argv){
	printf("Yeet\n");
	Board mainBoard;
	mainBoard.setValues();
	Pawn *test1, *test2, *test4, *taker;
	King *blackKing;
	mainBoard.addPiece(new Pawn(1, 1, true));
	mainBoard.addPiece(new Pawn(1, 2, true));
	mainBoard.addPiece(new Pawn(2, 2, false));
	//mainBoard.addPiece(new Pawn(3, 1, true));
	mainBoard.addPiece(new Queen(7,7,true));
	mainBoard.addPiece(new Rook(7,1,false));
	mainBoard.addPiece(new Bishop(5,5,false));
	mainBoard.addPiece(new Knight(5,0,true));

	mainBoard.addPiece(blackKing = new King(4,2,false));


	printf("%s\n", mainBoard.pieces[1][1]->canMoveTo(&mainBoard,1,2)?"true":"false");	//check for forward blocking			expect false
	printf("%s\n", mainBoard.pieces[1][1]->canMoveTo(&mainBoard,2,2)?"true":"false");	//check for white diagonal eat		expect true
	printf("%s\n", mainBoard.pieces[2][2]->canMoveTo(&mainBoard,2,1)?"true":"false");	//check for blacks moving down		expect true
	//printf("%s\n", mainBoard.pieces[2][2]->canMoveTo(&mainBoard,3,1)?"true":"false");	//check for blacks eating down		expect true
	//printf("%s\n", mainBoard.pieces[3][1]->canMoveTo(&mainBoard,4,2)?"true":"false");	//Check Scenario									expect true
	printf("%s\n", mainBoard.isInCheck(blackKing)?"true":"false");	//Check Scenario																		expect true
	printf("%s\n", mainBoard.pieces[5][0]->canMoveTo(&mainBoard,4,2)?"true":"false");	//Check Scenario	with Knight			expect true
	printf("%s\n", mainBoard.pieces[7][7]->canMoveTo(&mainBoard,5,5)?"true":"false");	//Check Queen diagonal						expect true
	printf("%s\n", mainBoard.pieces[7][7]->canMoveTo(&mainBoard,6,1)?"true":"false");	//Check Queen down								expect true
	printf("%s\n", mainBoard.pieces[5][5]->canMoveTo(&mainBoard,7,7)?"true":"false");	//Check Bishop										expect true
	//printf("%s\n", mainBoard.pieces[3][1]->canMoveTo(&mainBoard,4,2)?"true":"false");	//Check Scenario									expect true
	printf("%s\n", mainBoard.pieces[7][1]->canMoveTo(&mainBoard,7,7)?"true":"false");	//Check Rook										expect true
	printf("%s\n", mainBoard.pieces[5][0]->canMoveTo(&mainBoard,4,2)?"true":"false");	//Check Rook										expect true
	printf("%s\n", mainBoard.pieces[7][7]->canMoveTo(&mainBoard,7,7)?"true":"false");	//Check Rook										expect true



	/*
	if(test1->canMoveTo(&mainBoard,1,2)){
		printf("true\n");
	}
	else{printf("false\n");}
	if(test2->canMoveTo(&mainBoard,1,2)){
		printf("true\n");
	}
	else{printf("false\n");}
	printf("%s\n", test4->canMoveTo(&mainBoard,1,1)?"true":"false");
	*/
	//printf("%s\n", taker->canMoveTo(&mainBoard,7,7)?"true":"false");
	mainBoard.render();
}
