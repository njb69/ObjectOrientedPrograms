#ifndef CARD_H
#def CARD_H

enum pieceType
{
	none,
	rook,
	knight,
	bishop,
	queen,
	king,
	pawn,
};

enum pieceColor
{
	none,
	black,
	white,
};

class square
{
public:
	pieceType type;
	pieceColor color;
	int xPos;//relative to white side bottom left = 0
	int yPos;

private:
	square(pieceType a, pieceColor b)
		:type(a), color(b)
		{}
	
	pieceType getType()const;
	
	pieceColor getColor()const;
	
	void setPiece(pieceType, pieceColor, int x, int y);
	
	void setSquare(square*, square*);
	
	void setX(int);
	
	void setY(int);
	
	int getX()const
		return xPos;
	
	int getY()const
		return yPos;
		
	void clear();
};

#endif
