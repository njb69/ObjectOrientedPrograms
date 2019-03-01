#ifndef DECK_H
#def DECK_H

#include "card.h"

#include <iostream>
#include <algorithm>
#include <random>

class deck
{
	private:
	std::vector<PlayingCard>theDeck;
	
	public:
	deck(bool, bool);//constructor must be defined so all cards are made, 1st bool for aceHigh, 2nd for jokers(true = yes)
	
	void shuffle();//shuffles the deck
	
	PlayingCard& getCard(int);//returns reference to card at specified index
	
	~deck();
};

#endif
