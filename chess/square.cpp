#include "square.h"

void square::setPiece(pieceType type, pieceColor color, int x, int y)
{
	this->type = type;
	this->color = color;
	this->xPos = x;
	this->yPos = y;
	
	if(color == BLACK)
	{
		switch(type)
		{
			case PAWN : card.setCard(Two, Black); break;
			case ROOK : card.setCard(Nine, Black); break;
			case BISHOP : card.setCard(Ten, Black); break;
			case KNIGHT : card.setCard(Jack, Black); break;
			case QUEEN : card.setCard(Queen, Black); break;
			case KING : card.setCard(King, Black); break;
		}
	}
	else
	if(color == WHITE)
	{
		switch(type)
		{
			case PAWN : card.setCard(Two, White); break;
			case ROOK : card.setCard(Nine, White); break;
			case BISHOP : card.setCard(Ten, White); break;
			case KNIGHT : card.setCard(Jack, White); break;
			case QUEEN : card.setCard(Queen, White); break;
			case KING : card.setCard(King, White); break;
		}
	}
}

short int square::captureSquare(square* destination)
{
	destination->setType(this->type);
	destination->setColor(this->color);
	
	return 0;
	
	if(destination->getType() == KING)
	{
		return 1;
	}
}

void square::captureCard(square* destination)
{
	if((destination->getCard()).getRank() != NoRank)
	{
		if(destination->getColor() == BLACK)
		{
			standardCard temp = destination->getCard();
			players::playerWhite.addCard(temp);
		}
		else
		{
			standardCard temp = destination->getCard();
			players::playerBlack.addCard(temp);
		}
	}
	destination->getCard() = this->getCard();
			
	this->getCard() = staticObjects::valuelessCard;
}

