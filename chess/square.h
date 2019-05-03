#ifndef CARD_H
#define CARD_H

#include<iostream>

enum Rank
{
	Ace, //used if ace is low  0
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
	NoRank,
};

enum Suit
{
	Black,
	White,
	NoSuit,
};

///////////////////////////////////////////////

class standardCard
{
	private:
	Rank rank;
	Suit suit;
	
	public:
	standardCard() {};
	
	standardCard(Rank r, Suit s)//constructor: accepts int as index for Rank and int as index for Suit and makes card with cooresponding values
		:rank(r), suit(s)
		{}
	
	Rank getRank()const;
	Suit getSuit()const;
	
	void setCard(Rank r, Suit s)//sets card values DONT USE OUTSIDE OF BOARD CONSTRUCTION
		{rank = r; suit = s;}
	
	bool operator<(standardCard);
	bool operator>(standardCard);
	bool operator==(standardCard);
	bool operator!=(standardCard);
	
	standardCard& operator=(standardCard); //assignment operator overload 
};

/////////////////////////////////////////////




#endif
