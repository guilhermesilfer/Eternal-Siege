#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    virtual void processInput(sf::RenderWindow& window) = 0;
    virtual void update(float delta) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    sf::Vector2f position;
};

#endif

