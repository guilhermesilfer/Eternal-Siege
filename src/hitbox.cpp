#include "hitbox.h"
#include "entity.h"
#include <iostream>
#include <cmath>

Hitbox::Hitbox(Entity* p, float h, float w, std::vector<char> l) :
    parent(p),
    layers(l),
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
    for (auto l1 : layers) {
        for (auto l2 : h.layers) {
            if (l1 == l2) {
                return (fabsf(centerX() - h.centerX()) <= (halfWidth + h.halfWidth)) &&
                    (fabsf(centerY() - h.centerY()) <= (halfHeight + h.halfHeight));
            }
        }
    }
    return false;
}

void Hitbox::debugRender(sf::RenderWindow& window) {
    sf::RectangleShape box;
    box.setSize(sf::Vector2f(width, height));
    box.setOrigin(halfWidth, halfHeight);
    box.setFillColor(sf::Color::Yellow);
    box.setPosition(centerX(), centerY());
    window.draw(box);
}
