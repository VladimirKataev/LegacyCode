/*
	Written by Vladimir Kataev
*/
#include<iostream>
using namespace std;

int main(){
	char board[3][3] = {{'*','*', '*'},
			{'*', '*', '*'},
			{'*', '*', '*'}};
	int turn = 0, row, col;
	int winner = 0;
	char srch = 'X';
	while(turn != 9 && winner ==0){
		//----------------DISPLAY BOARD
		for(int a = 0; a < 3; a++){
			for(int b = 0; b < 3; b++){
				cout << board[a][b];
			}
			cout << endl;
		}
		cout << "Turn of Player " << (turn %2)+1 << endl;


		//----------------Get input, validated
		do{
			cout << "Make a move\nRow:";cin >> row;
			cout << "Column:"; cin >> col;
			row--; col--;
		}while((0 > row || row > 2)||
			(0 > col || col > 2)||
			board[row][col] != '*');
		if(turn%2 == 0)
			board[row][col] = 'X';
		else
			board[row][col] = 'O';



		//-----------------Check for win conditions
		if(turn%2 == 0)
			srch = 'X';
		else
			srch = 'O';

		if(board[0][0] == srch &&	//TL
			((board[0][1] == srch && board [0][2] == srch) ||//TOP
			(board[1][1] == srch && board [2][2] == srch) ||//DiagdownRight
			(board[1][0] == srch && board[2][0] == srch)	//left
			))
			{
			cout << "Winning Move!\n";
			return 0;
			}
		if(board[0][1] == srch && board[1][1] == srch && board[2][1] == srch){//mid down
			cout << "Winning Move!\n";
			return 0;
		}
		if(board[0][2] == srch && board[1][2] == srch && board[2][2] == srch){//right down
			cout << "Winning Move!\n";
			return 0;
		}
		if(board[0][2] == srch && board[1][1] == srch && board[2][0] == srch){  //Diag down left
			cout << "Winning Move!\n";
			return 0;
		}
		if(board[1][0] == srch && board[1][1] == srch && board[1][2] == srch){ //mid right
			cout << "Winning Move!\n";
			return 0;
		}
		if(board[2][0] == srch && board[2][1] == srch && board[2][2] == srch){
			cout << "Winning Move!\n";
			return 0;
		}

		turn++;
	}

	cout << "It tied, Draw\n";

	return 0;
}
/*
***
***
***
Turn of Player 1
Make a move
Row:1
Column:1
X**
***
***
Turn of Player 2
Make a move
Row:1
Column:2
XO*
***
***
Turn of Player 1
Make a move
Row:2
Column:2
XO*
*X*
***
Turn of Player 2
Make a move
Row:1
Column:3
XOO
*X*
***
Turn of Player 1
Make a move
Row:3
Column:3
Winning Move!

***
***
***
Turn of Player 1
Make a move
Row:1
Column:1
X**
***
***
Turn of Player 2
Make a move
Row:2
Column:2
X**
*O*
***
Turn of Player 1
Make a move
Row:3
Column:3
X**
*O*
**X
Turn of Player 2
Make a move
Row:1
Column:3
X*O
*O*
**X
Turn of Player 1
Make a move
Row:3
Column:1
X*O
*O*
X*X
Turn of Player 2
Make a move
Row:3
Column:2
X*O
*O*
XOX
Turn of Player 1
Make a move
Row:2
Column:3
X*O
*OX
XOX
Turn of Player 2
Make a move
Row:2
Column:1
X*O
OOX
XOX
Turn of Player 1
Make a move
Row:1
Column:2
It tied, Draw










*/
