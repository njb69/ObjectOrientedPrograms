#include "card.h"

Rank card::getSuit()const
{
	unsigned char suitOnly = static_cast <unsigned char> (cardData >> 4);//cut off bits representing rank in cardData, and shifts suit bits right, where they can be interpreted as int 	
	return suitOnly;
}

Suit card::getRank()const
{
	return static_cast <int> (cardData & 0xf;);//use bitwise and to get last 4 bits of cardData with 1111 (15 or hex f) 
}

Sprite card::getSprite()const
{
	Texture aceHeartsTexture;
	aceHeartsTexture.loadFromFile("data/images/aceHearts.png");
	Sprite aceHeartsSprite.(aceHeartsTexture);
	
	//etc
}

bool card::operator<(Card a, Card b)
{
  if (a.get_suit() < b.get_suit())
  {
    return true;
  }
 else
  if (b.get_suit() <= a.get_suit())
  {
    return false;
  }
}

bool card::operator>(Card a, Card b)
{
  return b < a;
}

bool card::operator==(Card a, Card b)
{
  return a.get_rank() == b.get_rank() &&
         a.get_suit() == b.get_suit();
}

bool card::operator!=(Card a, Card b)
{
  return !(a == b);
}


