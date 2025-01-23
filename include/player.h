#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"

class Player : public Entity {
public:
    Player();
    void processInput(sf::Event& event, Game& game);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window, Game& game);
    int getAmmo();
    int getHealth();

private:
    sf::Vector2f targetPosition;
    float speedPlayer = 200.f;
    int health;
    int ammo;
};

#endif

