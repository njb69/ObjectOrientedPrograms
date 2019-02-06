#ifndef WAR_H
#def WAR_H

#include <iostream>
#include "card.h"
#include "player.h"
#include "deck.h"

#include "card.h"
#include "deck.h"
#include "player.h"

class war
{
	private:
	player Player_1;
	player Player_2;
	
	vector<card>inPlayCards;
	
	void deal();//called from playGame ONLY
	
	public:
	int playGame(bool);//call from main to start and play game. accepts bool for ace high card(true) or low card
	
	~game();
};

#endif
