#include "board.h"

board::board()
{
	boardOfSquares[0][0].setPiece(ROOK, WHITE, 0, 0);
	boardOfSquares[1][0].setPiece(KNIGHT, WHITE, 1, 0);
	boardOfSquares[2][0].setPiece(BISHOP, WHITE, 2, 0);
	boardOfSquares[3][0].setPiece(QUEEN, WHITE, 3, 0);
	boardOfSquares[4][0].setPiece(KING, WHITE, 4, 0);
	boardOfSquares[5][0].setPiece(BISHOP, WHITE, 5, 0);
	boardOfSquares[6][0].setPiece(KNIGHT, WHITE, 6, 0);
	boardOfSquares[7][0].setPiece(ROOK, WHITE, 7, 0);
	boardOfSquares[0][7].setPiece(ROOK, BLACK, 0, 7);
	boardOfSquares[1][7].setPiece(KNIGHT, BLACK, 1, 7);
	boardOfSquares[2][7].setPiece(BISHOP, BLACK, 2, 7);
	boardOfSquares[3][7].setPiece(QUEEN, BLACK, 3, 7);
	boardOfSquares[4][7].setPiece(KING, BLACK, 4, 7);
	boardOfSquares[5][7].setPiece(BISHOP, BLACK, 5, 7);
	boardOfSquares[6][7].setPiece(KNIGHT, BLACK, 6, 7);
	boardOfSquares[7][7].setPiece(ROOK, BLACK, 7, 7);
	
	for(int i = 0; i < 7; i++)
	{
		boardOfSquares[i][1].setPiece(PAWN, WHITE, i, 1);
		boardOfSquares[i][6].setPiece(PAWN, BLACK, i, 6);
	}
	
	for(int i = 0; i < 7; i++)
	{
		for(int j = 2; j < 5; j++)
		{
			boardOfSquares[i][j].setPiece(noType, noColor, j, i);
		}
	}
}

square* board::validateMove(square* from, square* to)const
{
	if((from->getColor() != noColor) && (to->getX() <= 7) && (to->getY() <= 7) && (to->getColor() != from->getColor()))
	{
		return to;
	}
	else
	{}
}



square& board::getSquare(int x, int y) //needs validate move
{	
	x--;
	y--;
	
	return this->boardOfSquares[x][y];;
}

	

short int board::pawnMove(square* from, square* to)
{
	//validateMove(to);
	
	short int fromX = from->getX();
	short int fromY = from->getY();
	short int toX = to->getX();
	short int toY = to->getY();
	
	if((fromX == toX) && (fromY == toY + 1) && to->getType() == noType)//move up if no take
	{
		from->captureCard(to);
		return from->captureSquare(to);
	}
	else
	if(((fromX == toX + 1)||(fromX == toX - 1)) && (fromY == toY + 1) && to->getType() != noType)//move diagonal if take
	{
		from->captureCard(to);
		return from->captureSquare(to);
	}
	else
	{
		return 3;
	}
}

short int board::rookMove(square* from, square* to)
{
	//validateMove(to);
	
	short int fromX = from->getX();
	short int fromY = from->getY();
	short int toX = to->getX();
	short int toY = to->getY();
	
	if( ((fromX == toX) && (fromY != toY)) || ((fromX != toX) && (fromY == toY)) )
	{
		from->captureCard(to);
		return from->captureSquare(to);
	}
	else
	{return 3;}		
}

short int board::bishopMove(square* from, square* to)
{
	//validateMove(to);
	
	short int rise = from->getY() - to->getY();
	short int run = from->getX() - to->getX();
	
	int slope = rise / run;//slope of bishop move should be 1 or -1 
	
	if(slope == 1 || slope == -1)
	{
		from->captureCard(to);
		return from->captureSquare(to);
	}
	else
	{return 3;}		
}


short int board::knightMove(square* from, square* to)
{
	//validateMove(to);
	
	short int rise = from->getY() - to->getY();
	short int run = from->getX() - to->getX();
	
	double slope = rise / run;//slope of knight move should be 1/2 or -1/2 or 2 or -2 
	
	if( (slope == 1/2) || (slope == -1/2) || (slope == 2) || (slope == -2) )
	{
		from->captureCard(to);
		return from->captureSquare(to);
	}
	else
	{return 3;}
}	

short int board::queenMove(square* from, square* to)
{
	//validateMove(to);
	
	short int fromX = from->getX();
	short int fromY = from->getY();
	short int toX = to->getX();
	short int toY = to->getY();
	
	short int rise = from->getY() - to->getY();
	short int run = from->getX() - to->getX();
	
	double slope = rise / run;
	
	if( ((fromX == toX) && (fromY != toY)) || ((fromX != toX) && (fromY == toY)) )//horizontal or vertical
	{
		from->captureCard(to);
		return from->captureSquare(to);
	}
	else
	if(slope == 1 || slope == -1)//diagonal
	{
		from->captureCard(to);
		return from->captureSquare(to);
	}
	else
	{return 3;}		
}

short int board::kingMove(square* from, square* to)
{
	//validateMove(to);
	
	short int rise = from->getY() - to->getY();
	short int run = from->getX() - to->getX();
	
	rise *= rise;
	run *= run;
	
	if( rise == 1 || run == 1 )//front, back, left, right, diagonal
	{
		from->captureCard(to);
		return from->captureSquare(to);
	}
	else
	{return 3;}	
}
