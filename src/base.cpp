#include "base.h"
#include "player.h"
#include "projectile.h"
#include "game.h"

Base::Base() :
    Entity(sf::Vector2f(640, 400)),
    hitbox(this, 270.f, 520.f, {'P', 'Y'}),
    health(100)
{}

void Base::processInput(sf::Event& event, Game& game) {}

void Base::update(float delta, Game& game) {}

void Base::render(sf::RenderWindow& window, Game& game) {
    // renderiza a base
    sf::RectangleShape baseShape;
    baseShape.setSize(sf::Vector2f(500, 250));
    baseShape.setOrigin(sf::Vector2f(250, 125));
    baseShape.setFillColor(sf::Color::Transparent);
    baseShape.setOutlineColor(sf::Color::Green);
    baseShape.setOutlineThickness(10);
    baseShape.setPosition(getX(), getY());
    window.draw(baseShape);
}

int Base::getHealth() {
    return health;
}

int Base::loseHealth(int amount) {
    health -= amount;
    return health;
}

