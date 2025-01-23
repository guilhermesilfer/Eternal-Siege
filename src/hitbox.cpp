#include "hitbox.h"
#include "entity.h"
#include <iostream>
#include <cmath>

Hitbox::Hitbox(Entity* p, float h, float w) :
    parent(p),
    height(h),
    width(w),
    halfHeight(h/2.0),
    halfWidth(w/2.0)
{}

float Hitbox::centerX() {
    return parent->getX();
}

float Hitbox::centerY() {
    return parent->getY();
}

bool Hitbox::collided(Hitbox& h) {
    return (fabsf(centerX() - h.centerX()) <= (halfWidth + h.halfWidth)) &&
           (fabsf(centerY() - h.centerY()) <= (halfHeight + h.halfHeight));
}

void Hitbox::debugRender(sf::RenderWindow& window) {
    sf::RectangleShape box;
    box.setSize(sf::Vector2f(width, height));
    box.setOrigin(halfWidth, halfHeight);
    box.setFillColor(sf::Color::Yellow);
    box.setPosition(centerX(), centerY());
    window.draw(box);
}
