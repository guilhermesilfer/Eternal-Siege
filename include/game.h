#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

class Entity;
class Player;
class Enemy;

class Game {
public:
    Game();
    void run();
    void spawnEntity(Entity* entity);
    Player* getPlayer();
    std::vector<Enemy*> getEnemies();

private:
    void processInput();
    void update(float delta);
    void render();
    void spawnEnemy();

    sf::RenderWindow window;
    sf::Clock clock;
    std::vector<Entity*> entities;
    Player* player;
    float spawnTimer;
    float spawnInterval;

};

#endif

