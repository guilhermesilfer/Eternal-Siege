#include "projectile.h"
#include "player.h"
#include "game.h"
#include <iostream>
#include <cmath>

Projectile::Projectile(sf::Vector2f pos) : Entity(pos) {}

void Projectile::processInput(sf::Event& event, Game& game) {
}

//void Projectile::update(float delta, Game& game) {
//    // movimentação do projetil
//    sf::Vector2f direction = targetPosition - position;
//    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
//
//    if (distance > 5) {
//        direction /= distance;
//        position += direction * speed * delta;
//    }
//}
void Projectile::update(float delta, Game& game) {
    direction /= std::sqrt(direction.x * direction.x + direction.y * direction.y);
    position += direction * speedProjectile * delta;

    if (position.x < -100 || position.y < -100 || position.x > 1300 || position.y > 900) {
        //game.removeProjectile(this);
    }
}

void Projectile::render(sf::RenderWindow& window, Game& game) {
    sf::CircleShape projectileShape;
    projectileShape.setRadius(3);
    projectileShape.setOrigin(projectileShape.getRadius(), projectileShape.getRadius());
    projectileShape.setFillColor(sf::Color::Blue);
    projectileShape.setPosition(position.x, position.y);
    window.draw(projectileShape);
}

sf::Vector2f Projectile::setTargetPosition(float x, float y) {
    targetPosition.x = x;
    targetPosition.y = y;
    return targetPosition;
}
