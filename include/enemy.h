#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"
#include "hitbox.h"

class Enemy : public Entity {
public:
    Enemy();
    void processInput(sf::Event& event, Game& game);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window, Game& game);
    sf::Clock clock;
    float shootTimer;
    float shootInterval;
    Hitbox hitbox;

private:
    float speed = 50.f;
};

#endif

