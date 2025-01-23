#include "hud.h"
#include "player.h"
#include <string>

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

    sf::Font font;
    if (!font.loadFromFile("fonts/PressStart.ttf"))
    {
        exit(1);
    }

    // desenha a munição restante
    std::string ammoText = std::to_string(ammo);
    sf::Text leftAmmo;
    leftAmmo.setFont(font);
    leftAmmo.setString("Ammo: " + ammoText);
    leftAmmo.setCharacterSize(15);
    leftAmmo.setFillColor(sf::Color::White);
    leftAmmo.setStyle(sf::Text::Underlined);
    leftAmmo.setOrigin(270, 0);
    leftAmmo.setPosition(getX() + 10, getY() + 33);
    window.draw(leftAmmo);

    // desenha a vida restante
    Player* player = game.getPlayer();
    int healthPlayer = player->getHealth();
    std::string healthText = std::to_string(healthPlayer);
    sf::Text leftHealth;
    leftHealth.setFont(font);
    leftHealth.setString("Health: " + healthText);
    leftHealth.setCharacterSize(15);
    leftHealth.setFillColor(sf::Color::White);
    leftHealth.setStyle(sf::Text::Underlined);
    leftHealth.setOrigin(270, 0);
    leftHealth.setPosition(getX() + 10, getY() + 2);
    window.draw(leftHealth);
}

