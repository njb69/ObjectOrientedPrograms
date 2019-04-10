#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <iostream>
#include <vector>

class player
{
	private:
	std::vector<standardCard> deck;
	int remainingCards;
	
	public:
	standardCard playCard();//returns top of player's playHand
	
	void returnCard(standardCard);//takes the card won and puts it in back of deck
	
	void addCard(standardCard&); //adds passed card reference to deck
	
	int getNumRemainingCards()const;
};

#endif