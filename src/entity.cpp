#include "entity.h"

float Entity::getX() const {
    return position.x;
}

float Entity::getY() const {
    return position.y;
}

void Entity::setX(float x) {
    position.x = x;
}

void Entity::setY(float y) {
    position.y = y;
}

