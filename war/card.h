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
	Suit suit;
	Rank rank;
	
	public:
	card(int, int);//constructor: accepts int as index for Rank and int as index for Suit and makes card with cooresponding values
	Rank getRank()const;
	Suit getSuit()const;
	Sprite getSprite()const;
	~card();
};

#endif