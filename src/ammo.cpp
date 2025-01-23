#include "ammo.h"
#include "player.h"
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Ammo::Ammo(sf::Vector2f pos) :
    Entity(pos),
    hitbox(this, 32.f, 20.f, {'A'}),
    amount(30),
    lifeTimer(0),
    maxLifetime(10),
    blink(false),
    blinkTimer(0),
    blinkInterval(0.4)
{}

void Ammo::processInput(sf::Event& event, Game& game) {}

void Ammo::update(float delta, Game& game) {
    Player* player = game.getPlayer();
    if (player->hitbox.collided(this->hitbox)) {
        player->gainAmmo(10);
        game.despawnEntity(this);
        return;
    }

    float clockDelta = clock.restart().asSeconds();
    lifeTimer += clockDelta;
    if (lifeTimer >= maxLifetime / 2.0) {
        blinkTimer += clockDelta;
    }
    if (lifeTimer >= maxLifetime) {
        game.despawnEntity(this);
    }
}

void Ammo::render(sf::RenderWindow& window, Game& game) {
    if (lifeTimer >= maxLifetime / 2.0 && blinkTimer >= blinkInterval) {
        blink = !blink;
        blinkTimer = 0;
    }
    if (!blink) {
        sf::RectangleShape ammoShape;
        ammoShape.setSize(sf::Vector2f(32.f, 20.f));
        ammoShape.setOrigin(16.f, 10.f);
        ammoShape.setFillColor(sf::Color::Blue);
        ammoShape.setPosition(getX(), getY());
        window.draw(ammoShape);
    }
}
