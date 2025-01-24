#include "player.h"
#include "projectile.h"
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Player::Player() :
    Entity(sf::Vector2f(640, 400)),
    hitbox(this, 15.f, 15.f, {'P', 'A', 'X'}),
    targetPosition(sf::Vector2f(640, 400)),
    health(100),
    ammo(100),
    kills(0)
{}

void Player::processInput(sf::Event& event, Game& game) {
    // detecta o mouse
    if (event.type == sf::Event::MouseButtonPressed) {
        // para movimentar o player
        if (event.mouseButton.button == sf::Mouse::Right) {
            sf::Vector2f target(event.mouseButton.x, event.mouseButton.y);
            targetPosition = target;
        }

        // para spawn dos projeteis
        if (event.mouseButton.button == sf::Mouse::Left && ammo > 0) {
            Projectile* projectile = new Projectile(position, {'E'});
            projectile->setTargetPosition(event.mouseButton.x, event.mouseButton.y);
            projectile->direction = projectile->targetPosition - position;
            std::cout << projectile->direction.x << projectile->direction.y << std::endl;
            game.spawnEntity(projectile);
            ammo--;
        }
    }
}

void Player::update(float delta, Game& game) {
    // movimentação do player
    sf::Vector2f direction = targetPosition - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 6.0f) {
        direction /= distance;
        position += direction * speedPlayer * delta;
    }
}

void Player::render(sf::RenderWindow& window, Game& game) {
    // redenrização do player
    sf::CircleShape playerShape;
    playerShape.setRadius(10);
    playerShape.setOrigin(playerShape.getRadius(), playerShape.getRadius());
    playerShape.setFillColor(sf::Color::Cyan);
    playerShape.setOutlineColor(sf::Color::Blue);
    playerShape.setOutlineThickness(2.f);
    playerShape.setPosition(getX(), getY());
    window.draw(playerShape);
}

int Player::getHealth() {
    return health;
}

int Player::getAmmo() {
    return ammo;
}

int Player::getKills() {
    return kills;
}

int Player::gainAmmo(int amount) {
    ammo += amount;
    return ammo;
}

int Player::loseHealth(int amount) {
    health -= amount;
    return health;
}

int Player::increaseKills(int amount) {
    kills += amount;
    return kills;
}

