all:
	g++ -c main.cpp game.cpp player.cpp enemy.cpp
	g++ main.o game.o player.o enemy.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
version:
	g++ -c version.cpp
	g++ version.o -o sfml-version -lsfml-system
	./sfml-version
