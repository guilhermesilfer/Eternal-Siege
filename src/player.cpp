#include <iostream>
#include <cmath>

#include "player.h"

void Player::processInput(sf::Event& event) {
    std::cout << "banana" << std::endl;
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f target(event.mouseButton.x, event.mouseButton.y);
            targetPosition = target;
        }
    }
}

void Player::update(float delta) {
    sf::Vector2f direction = targetPosition - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 1.0f) {
        direction /= distance;
        position += direction * speed * delta;
    }
}

void Player::render(sf::RenderWindow& window) {
    sf::CircleShape playerShape(10.f);
    playerShape.setFillColor(sf::Color::Green);
    playerShape.setPosition(getX(), getY());
    window.draw(playerShape);
}

