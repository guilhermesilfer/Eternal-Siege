#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

#include "entity.h"

class Enemy : public Entity {
public:
    //Enemy(int initialX, int initialY);
    void processInput(sf::RenderWindow& window);
    void update(float delta);
    void render(sf::RenderWindow& window);

private:
    float speed = 50.f;
};

#endif

