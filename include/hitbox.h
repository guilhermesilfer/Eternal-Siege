#ifndef HITBOX_H
#define HITBOX_H

#include <SFML/Graphics.hpp>
#include "entity.h"

class Hitbox {
private:
    Entity* parent;

public:
    Hitbox(Entity* parent, float height, float width);
    float height;
    float width;
    float halfHeight;
    float halfWidth;
    float centerX();
    float centerY();
    bool collided(Hitbox& h);
    void debugRender(sf::RenderWindow& window);
};

#endif

