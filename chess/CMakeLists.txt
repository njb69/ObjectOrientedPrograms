g++ -c main.cpp card.cpp square.cpp board.cpp player.cpp warChess.cpp globalTextures.cpp

g++ main.o card.o square.o board.o player.o warChess.o globalTextures.o  -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

./sfml-app

//i couldnt get cmake to compile SFML after hours, talking to Prof Sutton etc
