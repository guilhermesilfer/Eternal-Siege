#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"

class Player : public Entity {
public:
    void processInput(sf::Event& event);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window);

private:
    sf::Vector2f targetPosition;
    float speed = 200.f;
};

#endif

