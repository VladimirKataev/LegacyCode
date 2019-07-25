#include<stdio.h>
class Piece;
class King;
class Board{
	public:
		bool isMoveOutOfBounds(unsigned int x, unsigned int y);
		int coordinateToInteger(char* coordinate);
		void setValues();
		Piece* pieces[8][8];																		// Y=0 for white
		void addPiece(Piece* toAdd);
		bool isColouredThere(unsigned int a, unsigned int b, bool white);
		void render();
		bool isInCheck(King* toCheck);
		Piece* returnPointer(unsigned int a, unsigned int b);
};
class Piece{
	public:
		bool isWhite;
		int x;
		int y;
		bool isReal;
		void setValues(unsigned int a, unsigned int b);
		virtual bool canMoveTo(Board* toCheck,unsigned int a, unsigned int b);
		Piece(unsigned int a,unsigned int b, bool c);
		virtual void render();
};
class Pawn : public Piece{
public:
	virtual bool canMoveTo(Board* where,unsigned int a, unsigned int b);
	void setValues(unsigned int a, unsigned int b, bool col);
	Pawn(unsigned int a,unsigned int b, bool c);
	virtual void render();
};
class Rook : public Piece{
	public:
	virtual bool canMoveTo(Board* where,unsigned int a, unsigned int b);
	void setValues(unsigned int a, unsigned int b);
	virtual void render();
	Rook(unsigned int a,unsigned int b, bool c);

};
class Knight : public Piece{
	public:
	virtual bool canMoveTo(Board* where,unsigned int a, unsigned int b);
	void setValues(unsigned int a, unsigned int b);
	virtual void render();
	Knight(unsigned int a, unsigned int b, bool c);

};
class Bishop : public Piece{
	public:
	virtual bool canMoveTo(Board* where,unsigned int a, unsigned int b);
	void setValues(unsigned int a, unsigned int b);
	virtual void render();
	Bishop(unsigned int a, unsigned int b, bool c);

};
class King : public Piece{
public:
	King(unsigned int a, unsigned int b, bool c);
	virtual bool canMoveTo(Board* where,unsigned int a, unsigned int b);
	void setValues(unsigned int a, unsigned int b);
	virtual void render();

};
class Queen : public Piece{
	public:
	Queen(unsigned int a, unsigned int b, bool c);
	virtual bool canMoveTo(Board* where,unsigned int a, unsigned int b);
	void setValues(unsigned int a, unsigned int b);
	virtual void render();

};
