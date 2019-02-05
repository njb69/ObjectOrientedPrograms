#include "card.h"
#include "deck.h"
#include "player.h"
#include "game.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using sf::Texture;
using sf::sprite;

int main()
{	
	bool aceHigh;
	std::cout<<"ace high or low 0/1?" <<std::endl;
	std::cin>>aceHigh;
	
	bool jokers;
	std::cout<<"jokers as highest 0/1?" <<std::endl;
	std::cin>>jokers;
	
	sf::RenderWindow window(sf::VideoMode(200, 200));
	
	game theGame(aceHigh, jokers);
	theGame.playGame();
	
	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
	
	return 0;
}
