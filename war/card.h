#ifndef CARD_H
#def CARD_H

#include<iostream>
#include <SFML/Graphics.hpp>

using sf::Sprite;

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
	Joker,//14
};

enum Suit
{
	Hearts,
	Diamonds,
	Clubs,
	Spades,
	No_Type,
};

class card
{
	private:
	unsigned char cardData;//8 bit storage for the card's suit and rank
	
	public:
	card(Rank r, Suit s)//constructor: accepts int as index for Rank and int as index for Suit and makes card with cooresponding values
		:cardData(static_cast<unsigned char>(s) << 4 | static_cast<unsigned char>(r))
		{}//cardData now contains a bit pattern of ssssrrrr. we're currently only using 2 bits for suit but we have 4 available
	
	Rank getRank()const;
	Suit getSuit()const;
	Sprite getSprite()const;
	~card();
	
	bool operator<(Card a, Card b);
	bool operator>(Card a, Card b);
	bool operator==(Card a, Card b);
	bool operator!=(Card a, Card b);
};

#endif
