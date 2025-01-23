#ifndef HITBOX_H
#define HITBOX_H

#include <SFML/Graphics.hpp>
#include "entity.h"

class Hitbox {
private:
    Entity* parent;
    std::vector<char> layers;

public:
    Hitbox(Entity* parent, float height, float width, std::vector<char> layers);
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

