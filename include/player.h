#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"

class Player : public Entity {
public:
    void processInput(sf::Event& event, Game& game);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window, Game& game);
    Player();

private:
    sf::Vector2f targetPosition;
    float speedPlayer = 200.f;
};

#endif

