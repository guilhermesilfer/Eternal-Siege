#include "enemy.h"
#include <cmath>

Enemy::Enemy(int initialX, int initialY) {
    x = static_cast<float>(initialX);
    y = static_cast<float>(initialY);
}

void Enemy::moveTowards(int targetX, int targetY, float deltaTime) {
    float dx = targetX - x;
    float dy = targetY - y;

    float distance = std::sqrt(dx * dx + dy * dy);

    if (distance > 0.0f) {
        dx /= distance;
        dy /= distance;

        x += dx * speed * deltaTime;
        y += dy * speed * deltaTime;
    }
}

int Enemy::getX() const {
    return static_cast<int>(x);
}

int Enemy::getY() const {
    return static_cast<int>(y);
}

