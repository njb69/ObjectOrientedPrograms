#include "square.h"

void square::setPiece(pieceType type, pieceColor color, int x, int y)
{
	this->type = type;
	this->color = color;
	xPos = x;
	yPos = y;
}

void square::setSquare(square* destination)
{
	destination->type = this->type;
	destination->color = this->color;
}

void square::clear()
{
	this->color = none;
	this->type = none;
}