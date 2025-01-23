#ifndef BASE_H
#define BASE_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"
#include "hitbox.h"

class Base : public Entity {
public:
    Base();
    void processInput(sf::Event& event, Game& game);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window, Game& game);
    int loseHealth(int amount);
    Hitbox hitbox;

private:
    int health;
};

#endif

