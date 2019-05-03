#include "card.h"

Suit standardCard::getSuit()const
{
	return suit;
}

Rank standardCard::getRank()const
{
	return rank;
}

bool standardCard::operator<(standardCard b)
{		
	return this->getRank() < b.getRank();
}

bool standardCard::operator>(standardCard b)
{
  return this->getRank() > b.getRank();
}

bool standardCard::operator==(standardCard b)
{
  return (this->getRank() == b.getRank());
}

bool standardCard::operator!=(standardCard b)
{
  return (this->getRank() != b.getRank());
}

standardCard& standardCard::operator=(standardCard card)
{
	rank = card.getRank();
	suit = card.getSuit();
	
	return *this;
}
