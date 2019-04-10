#include "card.h"
#include "square.h"
#include "player.h"
#include "board.h"
#include "warChess.h"

int main()
{
	warChess game;
	
	game.playChess();
	
	short int ultimateWinner = game.playWar();
	
	std::cout << "The winner is Player " << ultimateWinner << "!" << std::endl;
	
	return 0;
}
