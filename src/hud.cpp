#include "hud.h"
#include "player.h"
#include "base.h"
#include <string>

Hud::Hud() :
    Entity(sf::Vector2f(1280, 0))
{}

void Hud::processInput(sf::Event& event, Game& game) {}

void Hud::update(float delta, Game& game) {
    Base* base = game.getBase();
    baseHealth = base->getHealth();

    Player* player = game.getPlayer();
    health = player->getHealth();
    ammo = player->getAmmo();
    kills = player->getKills();
}

void Hud::render(sf::RenderWindow& window, Game& game) {
    //sf::RectangleShape rectangleShape;
    //rectangleShape.setSize(sf::Vector2f(270, 100));
    //rectangleShape.setOrigin(270, 0);
    //rectangleShape.setFillColor(sf::Color::Red);
    //rectangleShape.setPosition(getX(), getY());
    //window.draw(rectangleShape);

    sf::Font font;
    if (!font.loadFromFile("fonts/Pixelon.ttf")) {
        exit(1);
    }

    // desenha a vida restante da base
    std::string baseHealthText = std::to_string(baseHealth);
    sf::Text leftBaseHealth;
    leftBaseHealth.setFont(font);
    leftBaseHealth.setString("Base: " + baseHealthText);
    leftBaseHealth.setCharacterSize(20);
    leftBaseHealth.setFillColor(sf::Color::Black);
    leftBaseHealth.setStyle(sf::Text::Underlined);
    leftBaseHealth.setOrigin(270, 0);
    leftBaseHealth.setPosition(getX() + 10, getY() + 5);
    window.draw(leftBaseHealth);

    // desenha a vida restante
    std::string healthText = std::to_string(health);
    sf::Text leftHealth;
    leftHealth.setFont(font);
    leftHealth.setString("Health: " + healthText + "/100");
    leftHealth.setCharacterSize(20);
    leftHealth.setFillColor(sf::Color::Black);
    leftHealth.setStyle(sf::Text::Underlined);
    leftHealth.setOrigin(270, 0);
    leftHealth.setPosition(getX() + 10, getY() + 30);
    window.draw(leftHealth);

    // desenha a munição restante
    std::string ammoText = std::to_string(ammo);
    sf::Text leftAmmo;
    leftAmmo.setFont(font);
    leftAmmo.setString("Ammo: " + ammoText);
    leftAmmo.setCharacterSize(20);
    leftAmmo.setFillColor(sf::Color::Black);
    leftAmmo.setStyle(sf::Text::Underlined);
    leftAmmo.setOrigin(270, 0);
    leftAmmo.setPosition(getX() + 10, getY() + 55);
    window.draw(leftAmmo);

    // desenha as kills
    std::string killsText = std::to_string(kills);
    sf::Text totalKills;
    totalKills.setFont(font);
    totalKills.setString("Kills: " + killsText);
    totalKills.setCharacterSize(20);
    totalKills.setFillColor(sf::Color::Black);
    totalKills.setStyle(sf::Text::Underlined);
    totalKills.setOrigin(270, 0);
    totalKills.setPosition(getX() + 10, getY() + 80);
    window.draw(totalKills);

    if (health <= 0 || baseHealth <= 0) {
        // desenha o game over
        sf::Text gameOver;
        gameOver.setFont(font);
        gameOver.setString("GAME OVER");
        gameOver.setCharacterSize(100);
        gameOver.setFillColor(sf::Color::Black);
        gameOver.setOrigin(0, 0);
        gameOver.setPosition(400, 300);
        window.draw(gameOver);
    }
}

