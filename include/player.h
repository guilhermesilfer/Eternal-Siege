#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "entity.h"

class Player : public Entity {
public:
    void processInput(sf::Event& event);
    void update(float delta);
    void render(sf::RenderWindow& window);

private:
    sf::Vector2f targetPosition;
    float speed = 200.f;
};

#endif

