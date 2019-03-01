#include "deck.h"

deck::deck(bool aceHigh, bool joker)
{
	
	std::vector<PlayingCard>theDeck(54);//we're making room for jokers but may not use 
	
	int index = 0;
	int i = 1;
	while(i < 13)//12 possible ranks excluding jokers and aces
	{
		int j = 0;
		while(j < 4)//four types
		{
			PlayingCard tempCard(i, j);
			theDeck[index] = tempCard;
			index++;
			j++;
		}
		i++;
	}//48 card deck made
	
	int deckIndex = 48;
	
	if(joker)
	{
		PlayingCard redJoker(Red);
		theDeck[deckIndex] = joker;
		deckIndex++;
		PlayingCard blackJoker(Black);
		theDeck[deckIndex] = joker;
		deckIndex++;
	}
	else{}
	
	if(aceHigh)
	{
		int suitCt = 0;
		
		while(suitCt < 4)
		{
			PlayingCard highAce(13, suitCt);
			theDeck[deckIndex] = highAce;
			
			deckIndex++;
			suitCt++;
		}
	}
	else
	{
		int suitCt = 0;
		
		while(suitCt < 4)
		{
			PlayingCard lowAce(0, suitCt);
			theDeck[deckIndex] = highAce;
			
			deckIndex++;
			suitCt++;
		}
	}
	
}

void deck::shuffle()
{
	auto rng = std::default_random_engine {};
	std::shuffle(std::begin(theDeck), std::end(theDeck), rng);
}

PlayingCard& deck::getCard(int index)
{
	return theDeck[index];
}
