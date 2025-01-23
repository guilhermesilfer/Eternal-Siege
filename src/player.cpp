#include "player.h"
#include "projectile.h"
#include "game.h"
#include <iostream>
#include <cmath>

Player::Player() {
    position = sf::Vector2f(640, 400);
    targetPosition = sf::Vector2f(640, 400);
}

void Player::processInput(sf::Event& event, Game& game) {
    std::cout << "sus" << std::endl;
    std::cout << "sus" << std::endl;
    std::cout << "sus" << std::endl;
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            sf::Vector2f target(event.mouseButton.x, event.mouseButton.y);
            targetPosition = target;
        }

        if (event.mouseButton.button == sf::Mouse::Left) {
            Projectile* projectile = new Projectile(position);
            std::cout << projectile->position.x << " " << projectile->position.y << std::endl;
            game.spawnEntity(projectile);

            Projectile* pee = new Projectile(sf::Vector2f(800, 800) );
            std::cout << pee->position.x << " " << pee->position.y << std::endl;
            game.spawnEntity(pee);

            Projectile* poo = new Projectile(sf::Vector2f(800, 200) );
            std::cout << poo->position.x << " " << poo->position.y << std::endl;
            game.spawnEntity(poo);

            //game.despawnEntity();
        }
    }
}

void Player::update(float delta, Game& game) {
    // movimentação do player
    sf::Vector2f direction = targetPosition - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 1.0f) {
        direction /= distance;
        position += direction * speed * delta;
    }
}

void Player::render(sf::RenderWindow& window, Game& game) {
    sf::CircleShape playerShape(10.f);
    playerShape.setFillColor(sf::Color::Green);
    playerShape.setPosition(getX(), getY());
    window.draw(playerShape);
}

