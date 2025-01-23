#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"

class Projectile : public Entity {
public:
    void processInput(sf::Event& event, Game& game);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window, Game& game);
    Projectile(sf::Vector2f pos);

private:
    sf::Vector2f targetPosition;
    float speed = 500.f;
};

#endif

