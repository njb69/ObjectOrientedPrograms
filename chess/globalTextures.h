#ifndef GLOBALTEXTURES_H
#define GLOBALTEXTURES_H

#include <SFML/Graphics.hpp>

static sf::Sprite pieces[8][4];//for pieces only no blanks, not meant to represent board

namespace global_Textures
{
  static sf::Texture boardImage;
  static sf::Texture whiteRook;
  static sf::Texture whiteKnight;
  static sf::Texture whiteBishop;
  static sf::Texture whiteKing;
  static sf::Texture whiteQueen;
  static sf::Texture whitePawn;
  static sf::Texture blackRook;
  static sf::Texture blackKnight;
  static sf::Texture blackBishop;
  static sf::Texture blackKing;
  static sf::Texture blackQueen;
  static sf::Texture blackPawn;
}

namespace sfmlFunctions
{
  int makeCoordinates(int);//board's 0,0 is bottom left, SFMLs is top left so convert SFML to board
  // void makeMove(sf::Vector2f from, sf::Vector2f to)//should verify move and update board class
  // {
  //
  // }
}

sf::Sprite& getSpriteAtCoordinates(int, int);

#endif
