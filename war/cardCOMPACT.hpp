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

class normalCard
{
	private:
	unsigned char cardData;//8 bit storage for the card's suit and rank
	
	public:
	normalCard(Rank r, Suit s)//constructor: accepts int as index for Rank and int as index for Suit and makes card with cooresponding values
		:cardData(static_cast<unsigned char>(s) << 4 | static_cast<unsigned char>(r))
		{}//cardData now contains a bit pattern of ssssrrrr. we're currently only using 2 bits for suit but we have 4 available
	
	Rank getRank()const;
	Suit getSuit()const;
	Sprite getSprite()const;
	~card();
};

/////////////////////////////////////////////

class jokerCard
{
public:
  jokerCard(Color c)
    : color(static_cast<unsigned char>(c))
  { }

  Color get_color() const { return static_cast<Color>(color); }

private:
  unsigned char color;
};

///////////////////////////////////////////

union PlayingCardData
{
  PlayingCardData(Rank r, Suit s)
    : sc(r, s)
  { }

  PlayingCardData(Color c)
    : jc(c)
  { }

  normalCard sc;
  jokerCard jc;
};

//////////////////////////////////////////

enum PlayingCardKind
{
  Standard,
  Joker,
};

///////////////////////////////////////

class PlayingCard //the first bit of the 8 bit unsigned char will be the tag normalCard(1), jokerCard(0)
{
public:
  PlayingCard(Rank r, Suit s)
  { 
	PlayingCardData temp(r, s);
	
	theTagANDcard = static_cast<unsigned char>(temp | 10000000);
  }

  PlayingCard(Color c)
  { 
	PlayingCardData temp(c);
	
	theTagANDcard = static_cast<unsigned char>(temp);
  }

  bool is_standard() const { 
    int tag = static_cast<int>(theTagANDcard >> 7);
	
	return tag;
  }

  bool is_joker() const { 
    int tag = static_cast<int>(theTagANDcard >> 7);
	
	return tag;
  }

  StandardCard get_as_standard() const {
    assert(is_standard());
	
	unsigned char temp = theTagANDcard;
    temp<<;
	temp>>;//shake the tag bit
	
	return ((static_cast<PlayingCardData>(temp)).sc);
  }
 

  Rank get_rank() const {
    assert(is_standard());
	
	unsigned char temp = theTagANDcard;
    temp<<;
	temp>>;//shake the tag bit
	
	return ((static_cast<PlayingCardData>(temp)).sc.get_rank());
  }

  Suit get_suit() const { 
    assert(is_standard());
    
	unsigned char temp = theTagANDcard;
    temp<<;
	temp>>;//shake the tag bit
	
	return ((static_cast<PlayingCardData>(temp)).sc.get_suit());
  }

  JokerCard get_as_joker() const {
    assert(is_joker());
    
	return ((static_cast<PlayingCardData>(theTagANDcard)).jc);
  }

  Color get_color() const { 
    assert(is_joker());
    
	return ((static_cast<PlayingCardData>(theTagANDcard)).jc.get_color());
  }
  
  bool operator<(PlayingCard, PlayingCardCard);
	bool operator>(PlayingCardCard, PlayingCardCard);
	bool operator==(PlayingCardCard, PlayingCardCard);
	bool operator!=(PlayingCardCard, PlayingCardCard);

private:
  unsigned char theTagANDcard;
};


#endif