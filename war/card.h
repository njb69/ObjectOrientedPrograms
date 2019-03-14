#ifndef CARD_H
#def CARD_H

#include<iostream>
#include <SFML/Graphics.hpp>

//tagged union

using sf::Sprite;
using std::

enum Rank
{
	AceLow, //used if ace is low  0
	Two,//1
	Three,//2
	Four,//3
	Five,//4
	Six,//5
	Seven,//6
	Eight,//7
	Nine,//8
	Ten,//9
	Jack,//10
	Queen,//11
	King,//12
	AceHigh, //used if ace is high 13
};

enum Suit
{
	Hearts,
	Diamonds,
	Clubs,
	Spades,
};

enum Color
{
	Red,
	Black,
};

///////////////////////////////////////////////

class standardCard : PlayingCard
{
	private:
	unsigned char cardData;//8 bit storage for the card's suit and rank
	
	public:
	standardCard(Rank r, Suit s)//constructor: accepts int as index for Rank and int as index for Suit and makes card with cooresponding values
		:cardData(static_cast<unsigned char>(s) << 4 | static_cast<unsigned char>(r))
		{}//cardData now contains a bit pattern of ssssrrrr. we're currently only using 2 bits for suit but we have 4 available
	
	Rank getRank()const;
	Suit getSuit()const;
	Sprite getSprite()const;
	~card();
};

/////////////////////////////////////////////

class jokerCard : PlayingCard
{
public:
  jokerCard(Color c)
    : color(c)
  { }

  Color get_color() const { return color; }

private:
  Color color;
};

//////////////////////////////////////////

enum PlayingCardKind
{
  Standard,
  Joker,
};

///////////////////////////////////////

class PlayingCard
{
private:
  PlayingCardKind tag;
  
public:
  PlayingCard(Rank r, Suit s)
    : tag(Standard), data(r, s)
  { }

  PlayingCard(Color c)
    : tag(Joker), data(c)
  { }

  bool is_standard() const { 
    return tag == Standard;
  }

  bool is_joker() const { 
    return tag == Joker;
  }

  StandardCard get_as_standard() const {
    assert(is_standard());
    return data.sc;
  }

  Rank get_rank() const {
    assert(is_standard());
    return data.sc.get_rank();
  }

  Suit get_suit() const { 
    assert(is_standard());
    return data.sc.get_suit();
  }

  JokerCard get_as_joker() const {
    assert(is_joker());
    return data.jc;
  }

  Color get_color() const { 
    assert(is_joker());
    return data.jc.get_color();
  }
  
    bool operator<(PlayingCard, PlayingCardCard);
	bool operator>(PlayingCardCard, PlayingCardCard);
	bool operator==(PlayingCardCard, PlayingCardCard);
	bool operator!=(PlayingCardCard, PlayingCardCard);
	
	std::ostream& operator<<(ostream&, JokerCard const&);
	std::ostream& operator<<(ostream&, StandardCard const&);
	std::ostream& operator<<(ostream&, PlayingCard const&);
	
};


#endif
