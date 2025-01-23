#include "hud.h"
#include "player.h"

Hud::Hud() :
    Entity(sf::Vector2f(1280, 0))
{}

void Hud::processInput(sf::Event& event, Game& game) {}

void Hud::update(float delta, Game& game) {
    Player* player = game.getPlayer();
    ammo = player->getAmmo();
}

void Hud::render(sf::RenderWindow& window, Game& game) {
    sf::RectangleShape rectangleShape;
    rectangleShape.setSize(sf::Vector2f(270, 100));
    rectangleShape.setOrigin(270, 0);
    rectangleShape.setFillColor(sf::Color::Red);
    rectangleShape.setPosition(getX(), getY());
    window.draw(rectangleShape);
}

