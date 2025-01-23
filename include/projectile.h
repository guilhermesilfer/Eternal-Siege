#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "hitbox.h"
#include "game.h"

class Projectile : public Entity {
public:
    void processInput(sf::Event& event, Game& game);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window, Game& game);
    Projectile(sf::Vector2f pos);
    sf::Vector2f setTargetPosition(float x, float y);
    sf::Vector2f direction;
    sf::Vector2f targetPosition;
    Hitbox hitbox;

private:
    float speedProjectile = 500.f;
};

#endif

