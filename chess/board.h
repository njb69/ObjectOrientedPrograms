#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "square.h"
#include "card.h"

class board
{
private:
	square boardOfSquares [8][8];
	short int numWhite;
	short int numBlack;

public:
	board();//creates board with pieces in initial positions

	short int pawnMove(square*, square*);//accepts the square object the pawn occupies and the square obj of its destination

	short int rookMove(square*, square*);

	short int bishopMove(square*, square*);

	short int knightMove(square*, square*);

	short int queenMove(square*, square*);

	short int kingMove(square*, square*);

	square& getSquare(int, int);//returns reference to the square at the input x,y BOARD POSITION (not index) square has no assignment overload so accidental 
								//assignment = error

	short int getNumWhite()const;

	short int getNumBlack()const;

	square* validateMove(square*, square*)const;//called from a board space to make sure the destination is on the board, a friendly isn't there, and there's a piece @ the move from position
										//if invalid destination recursive call till one is given
};

#endif
