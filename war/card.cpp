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


std::ostream&
operator<<(std::ostream& os, Suit s)
{
  switch (s) {
  case Clubs: return os << "C";
  case Spades: return os << "S";
  case Hearts: return os << "H";
  case Diamonds: return os << "D";
  }
}


std::ostream&
operator<<(std::ostream& os, Rank r)
{
  switch (r) {
  case Ace: return os << "A";
  case Two: return os << "2";
  case Three: return os << "3";
  case Four: return os << "4";
  case Five: return os << "5";
  case Six: return os << "6";
  case Seven: return os << "7";
  case Eight: return os << "8";
  case Nine: return os << "9";
  case Ten: return os << "T";
  case Jack: return os << "J";
  case Queen: return os << "Q";
  case King: return os << "K";
  }
}


std::ostream& operator<<(ostream& os, JokerCard const& joker)
{
	switch (joker.get_color())
	{
		case Red:
			return os << "Red";
		case Black:
			return os << "Black";
	}
}


std::ostream& operator<<(ostream& os, standardCard const& sc)
{
	return os << sc.getRank() << sc.getSuit();
}


std::ostream& operator<<(ostream& os, PlayingCard const& pc)
{
	if(pc.is_standard)
	{
		return os << static_cast<standardCard const&>(pc);
	}
	else
	{
		return os << static_cast<jokerCard const&>(pc);
	}
}
