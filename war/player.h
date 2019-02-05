#ifndef PLAYER_H
#def PLAYER_H

#include "card.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class player
{
	private:
	std::vector<card> playHand;
	std::vector<card> returnHand;
	int remainingCards;
	
	public:
	card playCard();//returns top of player's playHand
	
	void returnCard(card, bool)//takes the card won and a boolean for top(true) or bottom of returnHand (face down deck)
	
	void moveDeck(); //moves returnHand to playHand
	
	void addCard(card&); //adds passed card reference to playHand(for dealing)
	
	int getNumRemainingCards()const;
	
	~player();
};

#endif