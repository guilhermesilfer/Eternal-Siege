all:
	g++ -c main.cpp game.cpp player.cpp enemy.cpp
	g++ main.o game.o player.o enemy.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app

