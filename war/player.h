#ifndef PLAYER_H
#def PLAYER_H

#include "card.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class player
{
	private:
	std::vector<PlayingCard> playHand;
	std::vector<PlayingCard> returnHand;
	int remainingCards;
	
	public:
	PlayingCard playCard();//returns top of player's playHand
	
	void returnCard(PlayingCard, bool)//takes the card won and a boolean for top(true) or bottom of returnHand (face down deck)
	
	void moveDeck(); //moves returnHand to playHand
	
	void addCard(PlayingCard&); //adds passed card reference to playHand(for dealing)
	
	int getNumRemainingCards()const;
	
	~player();
};

#endif
