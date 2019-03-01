#include <iostream>
#include "square.h"

class board
{
private:
	square boardOfSquares [8][8];
	short int numWhite;
	short int numBlack;

public:
	board();//creates board with pieces in initial positions
	
	void pawnMove(square*, square*);//accepts the square object the pawn occupies and the square obj of its destination
	
	void rookMove(square*, square*);
	
	void bishopMove(square*, square*);
	
	void knightMove(square*, square*);
	
	void queenMove(square*, square*);
	
	void kingMove(square*, square*);
	
	short int getNumWhite()const;
	
	short int getNumBlack()const;
	
	square* validateMove(square*)const;//called from a piece move to make sure the destination is on the board, and a friendly isn't there 
										//if invalid destination recursive call till one is given
};

