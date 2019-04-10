#include "player.h"

standardCard player::playCard()
{
	if(deck.size() != 0)//out of cards in both hands should be handled using remainingCards value in player obj
	{
		standardCard temp = deck.front();
		
		deck.erase(deck.begin());//remove card and memory
		
		deck.shrink_to_fit();//just in case ^ didn't work
		
		remainingCards--;
		
		return temp;
	}
	else
	{
		std::cout<<"a player lost. exiting..." << std::endl;
		exit(0);
	}
}

void player::returnCard(standardCard wonCard)
{
	deck.push_back(wonCard);
	remainingCards++;
}

void player::addCard(standardCard& toAdd)
{
	deck.push_back(toAdd);
	remainingCards++;
}

int player::getNumRemainingCards()const
{
	return remainingCards;
}
	
		
		