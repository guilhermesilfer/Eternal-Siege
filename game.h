#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "player.h"
#include "enemy.h"

class Game {
public:
    Game();
    void run();

private:
    void processInput();
    void update(float deltaTime);
    void render();
    void spawnEnemy();

    sf::RenderWindow window;
    sf::Clock clock;
    Player player;
    std::vector<Enemy> enemies;
    float spawnTimer;
    float spawnInterval;
};

#endif

