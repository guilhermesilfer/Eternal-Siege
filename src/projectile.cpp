#include "projectile.h"
#include "player.h"
#include "game.h"
#include <iostream>
#include <cmath>

Projectile::Projectile(sf::Vector2f pos) : Entity(pos) {}

void Projectile::processInput(sf::Event& event, Game& game) {
}

void Projectile::update(float delta, Game& game) {
    // movimentação do projetil
    sf::Vector2f direction = targetPosition - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 1.0f) {
        direction /= distance;
        position += direction * speed * delta;
    }
}

void Projectile::render(sf::RenderWindow& window, Game& game) {
    sf::CircleShape projectileShape(3.0f);
    projectileShape.setFillColor(sf::Color::Blue);
    projectileShape.setPosition(position.x, position.y);
    window.draw(projectileShape);
}

