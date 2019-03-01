#include "card.h"

Rank normalCard::getSuit()const
{
	unsigned char suitOnly = static_cast <unsigned char> (cardData >> 4);//cut off bits representing rank in cardData, and shifts suit bits right, where they can be interpreted as int 	
	return suitOnly;
}

Suit normalCard::getRank()const
{
	return static_cast <int> (cardData & 0xf;);//use bitwise and to get last 4 bits of cardData with 1111 (15 or hex f) 
}

Sprite normalCard::getSprite()const
{
	Texture aceHeartsTexture;
	aceHeartsTexture.loadFromFile("data/images/aceHearts.png");
	Sprite aceHeartsSprite.(aceHeartsTexture);
	
	//etc
}

bool PlayingCard::operator<(PlayingCard a, PlayingCardCard b)
{
	if(a.is_joker() || b.is_joker())
	{
		if(a.is_joker() && b.is_joker())
			{return false;}
		else
			{return a.is_joker()}
	}
		
	return a.get_as_standard().get_rank() < b.get_as_standard().get_rank();
}

bool PlayingCard::operator>(PlayingCard a, PlayingCardCard b)
{
  return b < a;
}

bool PlayingCard::operator==(PlayingCard a, PlayingCardCard b)
{
  if(a.is_joker() && b.is_joker())
	{return true;}
else
  if(a.is_joker() || b.is_joker())
	{return false;}
  
  return (a.get_as_standard().get_rank() == b.get_as_standard().get_rank());
}

bool PlayingCard::operator!=(PlayingCard a, PlayingCardCard b)
{
  return !(a == b);
}
