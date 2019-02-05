void game::deal(bool aceHigh, bool jokers)
{
	deck dealDeck(aceHigh, jokers);//create a deck
	
	dealDeck.shuffle();
	
	int remaining = 52;
	
	if(jokers)
	{
		remaining = 54;
	}
	else{}
	
	int index = 0;
	while(remaining > index)
	{
		player1.addCard(dealDeck.getCard(index));
		player2.addCard(dealDeck.getCard(index));
		index++;
	}

	
		

int game::playGame(bool aceHigh)
{
	this->deal();
	
	int index = 0;
	
	bool play = true;
	while(play)
	{
		if(player1.getNumRemainingCards() == 0)
		{
			std::cout<<"Player 1 wins!" << std::endl;
			return 0;
		}
		elseif(player2.getNumRemainingCards() == 0)
		{
			std::cout<<"Player 2 wins!" << std::endl;
			return 0;
		}
		else
		{
			inPlayCards.push_back(player1.playCard());
			inPlayCards.push_back(player2.playCard());
			
			if(inPlayCards[index] > inPlayCards[index + 1])//player 1 wins
			{
				std::cout<<"place cards on top or bottom of return deck?"<<std::endl;//replace with buttons
				
				bool tORb;
				
				std::cin>>tORb;
				
				int pot = inPlayCards.size();
				while(pot > 0)
				{
					player1.returnCard(inPlayCards[index]);
					pot--;
					index++;
				}
				
				index = 0;
				
				inPlayCards.clear();
				inPlayCards.resize(0);
			}
			elseif(inPlayCards[index] < inPlayCards[index + 1])//player 2 wins
			{
				std::cout<<"place cards on top or bottom of return deck?"<<std::endl;//replace with buttons
				
				bool tORb;
				
				std::cin>>tORb;
				
				int pot = inPlayCards.size();
				while(pot > 0)
				{
					player2.returnCard(inPlayCards[index]);
					pot--;
					index++;
				}
				
				index = 0;
				
				inPlayCards.clear();
				inPlayCards.resize(0);
			}
			elseif(inPlayCards[index] == inPlayCards[index + 1])//war
			{
				if(player1.getNumRemainingCards() < 2)
				{
					std::cout<<"Player 2 wins!" << std::endl;
					return 0;
				}
				elseif(player2.getNumRemainingCards() < 2)
				{
					std::cout<<"Player 1 wins!" << std::endl;
					return 0;
				}
				else
				{
					inPlayCards.push_back(player1.playCard());
					inPlayCards.push_back(player1.playCard());
					inPlayCards.push_back(player2.playCard());
					inPlayCards.push_back(player2.playCard());
					
					index += 4;//start compare on next loop at played up, not the face downs we just added 
				}
			}
		}
	}
}
				
				