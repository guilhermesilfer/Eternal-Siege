#include "entity.h"

Entity::Entity() {}

Entity::Entity(sf::Vector2f pos) : position(pos) {}

float Entity::getX() const {
    return position.x;
}

float Entity::getY() const {
    return position.y;
}

