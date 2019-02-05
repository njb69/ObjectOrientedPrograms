#include "card.h"

card::card(int rankIndex, int suitIndex)
{
	Rank rankValues[15] = {AceLow, Two, Three, Four, Five, Six, Seven, Eight, Nine,
							Ten, Jack, Queen, King, AceHigh, Joker};
	
	Suit suitValues[5] = {Hearts, Diamonds, Clubs, Spades, No_Type};
	
	rank = rankValues[rankIndex];
	suit = suitValues[suitIndex];
}

Rank card::getRank()const
{
	return rank;
}

Suit card::getSuit()const
{
	return suit;
}

Sprite card::getSprite()const
{
	Texture aceHeartsTexture;
	aceHeartsTexture.loadFromFile("data/images/aceHearts.png");
	Sprite aceHeartsSprite.(aceHeartsTexture);
	
	//etc
}