#ifndef DECK_H
#def DECK_H

#include "card.h"

#include <iostream>
#include <algorithm>
#include <random>

class deck
{
	private:
	std::vector<card>theDeck;
	
	public:
	deck(bool, bool);//constructor must be defined so all cards are made, 1st bool for aceHigh, 2nd for jokers(true = yes)
	
	void shuffle();//shuffles the deck
	
	card& getCard(int);//returns reference to card at specified index
	
	~deck();
};

#endif