#ifndef AMMO_H
#define AMMO_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"
#include "hitbox.h"

class Ammo : public Entity {
public:
    Ammo(sf::Vector2f pos);
    void processInput(sf::Event& event, Game& game);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window, Game& game);
    Hitbox hitbox;

private:
    int amount;
    sf::Clock clock;
    float lifeTimer;
    float maxLifetime;
    bool blink;
    float blinkTimer;
    float blinkInterval;
};

#endif
