#include "player.h"

#include "player.h"
#include <cmath>

void Player::setTarget(const sf::Vector2f& target) {
    targetPosition = target;
}

void Player::moveTowardsMouse(float deltaTime) {
    sf::Vector2f direction = targetPosition - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 1.0f) {
        direction /= distance;
        position += direction * speed * deltaTime;
    }
}

float Player::getX() const {
    return position.x;
}

float Player::getY() const {
    return position.y;
}

