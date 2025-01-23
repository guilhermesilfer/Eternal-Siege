#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "game.h"

class Entity {
public:
    Entity();
    Entity(sf::Vector2f pos);
    virtual void processInput(sf::Event& event, Game& game) = 0;
    virtual void update(float delta, Game& game) = 0;
    virtual void render(sf::RenderWindow& window, Game& game) = 0;
    sf::Vector2f position;
    float getX() const;
    float getY() const;
};

#endif

