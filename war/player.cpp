#include "player.h"

PlayingCard player::playCard()
{
	if(playHand.size() != 0)//out of cards in both hands should be handled using remainingCards value in player obj
	{
		PlayingCard temp = playHand.front();
		
		playHand.erase(playHand.front());//remove card and memory
		
		playHand.shrink_to_fit();//just in case ^ didn't work
		
		remainingCards--;
		
		app.draw(temp.getSprite);
		
		return temp;
	}
	elseif(returnHand.size() != 0)
	{
		this->moveDeck();
		this->playCard();
	}
	else
	{
		std::cout<<"a player lost. exiting..." << std::endl;
		exit(0);
	}
}

void player::returnCard(PlayingCard wonCard, bool putOnTop)
{
	if(putOnTop)
	{
		std::size_t size = returnHand.size();
		
		while(size > 0)
		{
			returnHand.push_back(returnHand[size-1]);
			size--;
		}
		returnHand[0] = wonCard;
		
		remainingCards++;
	}
	else
	{
		returnHand.push_back(wonCard);
		remainingCards++;
	}
}

void player::moveDeck()
{
	playHand.clear();//just in case
	playHand.resize(0);//just in case
	
	size_t size = returnHand.size();
	
	int i = 0;
	while(size > 0)
	{
		playHand.push_back(returnHand[i]);
		i++;
		size--;
	}
	returnHand.clear();
	returnHand.resize(0);
}

void player::addCard(card& toAdd)
{
	playHand.push_back(toAdd);
	remainingCards++;
}

int player::getNumRemainingCards()const
{
	return remainingCards;
}
