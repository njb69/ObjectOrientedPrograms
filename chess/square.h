#ifndef SQUARE_H
#define SQUARE_H

#include "card.h"
#include "player.h"
#include "playersNamespace.h"

namespace staticObjects
{
	static const standardCard valuelessCard(NoRank, NoSuit);
}

enum pieceType
	{
		noType,
		ROOK,
		KNIGHT,
		BISHOP,
		QUEEN,
		KING,
		PAWN,
	};

enum pieceColor
	{
		noColor,
		BLACK,
		WHITE,
	};
	
class square
{
private:
	pieceType type;
	pieceColor color;
	standardCard card;
	int xPos;//relative to white side bottom left = 0
	int yPos;

public:
	square(pieceType a = noType, pieceColor b = noColor, standardCard c = staticObjects::valuelessCard, int x = -1, int y = -1)
		:type(a), color(b), xPos(x), yPos(y)
		{}
	
	pieceType getType()const
		{return type;}
	
	pieceColor getColor()const
		{return color;}
		
	standardCard getCard()//allows for capture and removal of a pieces card
		{return card;}
		
	void setType(pieceType t)
		{type = t;}
		
	void setColor(pieceColor c)
		{color = c;}
	
	void setPiece(pieceType, pieceColor, int x, int y);//initialize the position (x and y) and piece attributes on an existing piece
														//DONT USE AFTER BOARD HAS BEEN ASSEMBLED
	
	short int captureSquare(square*);//accepts pointer to square to capture (empty or occupied) and sets it's piece values (x and y dont change) to that of the  
								//square the function is called from, also clears the piece data of the calling square {ultimately the piece has moved to the pointer's square}
	
	void captureCard(square*);//returns the card obtained from taking an opponents piece
	
	int getX()const
		{return xPos;}
	
	int getY()const
		{return yPos;}
};
#endif
