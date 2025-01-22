#include "player.h"
#include <cmath>

void Player::processInput(sf::RenderWindow window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f target(event.mouseButton.x, event.mouseButton.y);
                targetPosition = target;
            }
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

void Player::render(sf::RenderWindow window) {
    sf::CircleShape playerShape(10.f);
    playerShape.setFillColor(sf::Color::Green);
    playerShape.setPosition(getX(), getY());
    window.draw(playerShape);
}

