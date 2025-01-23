#include "projectile.h"
#include "player.h"
#include "enemy.h"
#include "game.h"
#include <iostream>
#include <cmath>

Projectile::Projectile(sf::Vector2f pos) :
    Entity(pos),
    hitbox(this, 3.f, 3.f)
{}

void Projectile::processInput(sf::Event& event, Game& game) {}

void Projectile::update(float delta, Game& game) {
    direction /= std::sqrt(direction.x * direction.x + direction.y * direction.y);
    position += direction * speedProjectile * delta;

    if (position.x < -100 || position.y < -100 || position.x > 1300 || position.y > 900) {
        //game.despawnEntity(this);
    }

    std::vector<Enemy*> enemies = game.getEnemies();
    for (Enemy* enemy : enemies) {
        if (enemy->hitbox.collided(this->hitbox)) {
            std::cout << "AAAAAAAAAAAAAAAA" << std::endl;
            game.despawnEntity(enemy);
            game.despawnEntity(this);
        }
    }
}

void Projectile::render(sf::RenderWindow& window, Game& game) {
    sf::CircleShape projectileShape;
    projectileShape.setRadius(3);
    projectileShape.setOrigin(projectileShape.getRadius(), projectileShape.getRadius());
    projectileShape.setFillColor(sf::Color::Blue);
    projectileShape.setPosition(position.x, position.y);
    window.draw(projectileShape);
    hitbox.debugRender(window);
}

sf::Vector2f Projectile::setTargetPosition(float x, float y) {
    targetPosition.x = x;
    targetPosition.y = y;
    return targetPosition;
}
