#include "player.h"
#include "projectile.h"
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Player::Player() :
    Entity(sf::Vector2f(640, 400)),
    targetPosition(sf::Vector2f(640, 400)),
    health(100),
    ammo(100)
{}

void Player::processInput(sf::Event& event, Game& game) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            sf::Vector2f target(event.mouseButton.x, event.mouseButton.y);
            targetPosition = target;
        }

        // spawn dos projeteis
        if (event.mouseButton.button == sf::Mouse::Left && ammo > 0) {
            Projectile* projectile = new Projectile(position);
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
    sf::CircleShape playerShape;
    playerShape.setRadius(10);
    playerShape.setOrigin(playerShape.getRadius(), playerShape.getRadius());
    playerShape.setFillColor(sf::Color::Green);
    playerShape.setPosition(getX(), getY());
    window.draw(playerShape);
}

int Player::getHealth() {
    return health;
}

int Player::getAmmo() {
    return ammo;
}

