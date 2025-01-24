#include "ammo.h"
#include "player.h"
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Ammo::Ammo(sf::Vector2f pos) :
    Entity(pos),
    hitbox(this, 20.f, 32.f, {'A'}),
    amount(30),
    lifeTimer(0),
    maxLifetime(10),
    blink(false),
    blinkTimer(0),
    blinkInterval(0.4)
{}

void Ammo::processInput(sf::Event& event, Game& game) {}

void Ammo::update(float delta, Game& game) {
    // checa se houve colisão
    Player* player = game.getPlayer();
    if (player->hitbox.collided(this->hitbox)) {
        player->gainAmmo(5);
        game.despawnEntity(this);
        return;
    }

    // temporizador da caixa de munição
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
        // retangulo da caixa de munição
        sf::RectangleShape ammoShape;
        ammoShape.setSize(sf::Vector2f(32.f, 20.f));
        ammoShape.setOrigin(16.f, 10.f);
        ammoShape.setFillColor(sf::Color::Blue);
        ammoShape.setPosition(getX(), getY());
        window.draw(ammoShape);

        // texto da caixa de munição
        sf::Font font;
        if (!font.loadFromFile("fonts/Pixelon.ttf")) {
            exit(1);
        }
        sf::Text ammoText;
        ammoText.setFont(font);
        ammoText.setString("5");
        ammoText.setCharacterSize(20);
        ammoText.setFillColor(sf::Color::White);
        ammoText.setOrigin(8, 12);
        ammoText.setPosition(getX(), getY());
        window.draw(ammoText);

    }
}
