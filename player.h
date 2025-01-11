#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>

class Player {
public:
    void setTarget(const sf::Vector2f& target);
    void moveTowardsMouse(float deltaTime);
    float getX() const;
    float getY() const;

private:
    sf::Vector2f position;
    sf::Vector2f targetPosition;
    float speed = 200.f;
};

#endif

