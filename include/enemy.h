#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"

class Enemy : public Entity {
public:
    void processInput(sf::Event& event, Game& game);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window, Game& game);
    Enemy();

private:
    float speed = 50.f;
};

#endif

