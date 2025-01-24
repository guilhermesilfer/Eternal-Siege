#include "enemy.h"
#include "game.h"
#include "player.h"
#include "base.h"
#include "projectile.h"
#include <cmath>
#include <cstdlib>

Enemy::Enemy() :
    shootTimer(0),
    shootInterval(2.0f),
    hitbox(this, 15.f, 15.f, {'E', 'X', 'Y'})
{
    // sistema de spawn dos inimigos

    int axisDice = std::rand() % 2;
    int side = std::rand() % 2;

    // horizontal
    if (axisDice == 1) {
        if (side == 1)
            position.x = 1380;
        else if (side == 0)
            position.x = -100;
        position.y = std::rand() % 900;
    } // vertical
    else if (axisDice == 0) {
        if (side == 1)
            position.y = -100;
        if (side == 0)
            position.y = 900;
        position.x = std::rand() % 1380;
    }
}

void Enemy::processInput(sf::Event& event, Game& game) {}

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

    // spawn dos projeteis
    shootTimer += clock.restart().asSeconds();
    if (shootTimer >= shootInterval) {
        Projectile* projectile = new Projectile(position, {'P'});
        projectile->setTargetPosition(player->getX(), player->getY());
        projectile->direction = projectile->targetPosition - position;
        game.spawnEntity(projectile);
        shootTimer = 0;
    }

    if (player->hitbox.collided(this->hitbox)) {
        player->loseHealth(10);
        game.despawnEntity(this);
    }
    Base* base = game.getBase();
    if (base->hitbox.collided(this->hitbox)) {
        base->loseHealth(10);
        game.despawnEntity(this);
    }
}

void Enemy::render(sf::RenderWindow& window, Game& game) {
    sf::CircleShape enemyShape;
    enemyShape.setRadius(10);
    enemyShape.setOrigin(enemyShape.getRadius(), enemyShape.getRadius());
    enemyShape.setFillColor(sf::Color::Red);
    enemyShape.setPosition(getX(), getY());
    window.draw(enemyShape);
    hitbox.debugRender(window);
}
