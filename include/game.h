#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

class Entity;
class Player;
class Base;
class Enemy;

class Game {
public:
    Game();
    void run();
    void spawnEntity(Entity* entity);
    void despawnEntity(Entity* entity);
    Player* getPlayer();
    Base* getBase();
    std::vector<Enemy*> getEnemies();

private:
    static sf::ContextSettings createSettings();
    void processInput();
    void update(float delta);
    void render();
    void spawnEnemy();

    sf::RenderWindow window;
    sf::Clock clock;
    std::vector<Entity*> entities;
    Player* player;
    Base* base;
    float spawnTimer;
    float spawnInterval;

};

#endif

