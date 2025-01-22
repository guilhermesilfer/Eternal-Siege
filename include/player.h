#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "entity.h"

class Player : public Entity {
public:
    void processInput(sf::RenderWindow window);
    void update(float delta);
    void render(sf::RenderWindow window);
    void moveTowardsMouse(float deltaTime);

private:
    sf::Vector2f targetPosition;
    float speed = 200.f;
};

#endif

