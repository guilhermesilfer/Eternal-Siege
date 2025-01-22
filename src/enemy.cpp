#include "enemy.h"
#include "game.h"
#include "player.h"
#include <cmath>

void Enemy::processInput(sf::Event& event) {}

void Enemy::update(float delta, Game& game) {
    Player* player = game.getPlayer();
    int targetX = player->getX();
    int targetY = player->getY();
    float dx = targetX - position.x;
    float dy = targetY - position.y;
    float distance = std::sqrt(dx * dx + dy * dy);
    if (distance > 0.0f) {
        dx /= distance;
        dy /= distance;
        position.x += dx * speed * delta;
        position.y += dy * speed * delta;
    }
}

void Enemy::render(sf::RenderWindow& window) {}
