#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"

class Enemy : public Entity {
public:
    void processInput(sf::Event& event);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window);

private:
    float speed = 50.f;
};

#endif

