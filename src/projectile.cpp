#include "projectile.h"
#include "player.h"
#include "base.h"
#include "ammo.h"
#include "enemy.h"
#include "game.h"
#include <iostream>
#include <cmath>

Projectile::Projectile(sf::Vector2f pos, std::vector<char> layers) :
    Entity(pos),
    hitbox(this, 3.f, 3.f, layers)
{}

void Projectile::processInput(sf::Event& event, Game& game) {}

void Projectile::update(float delta, Game& game) {
    // movimentação do projetil
    direction /= std::sqrt(direction.x * direction.x + direction.y * direction.y);
    position += direction * speedProjectile * delta;

    // remove o projetil se sair da tela
    if (position.x < -100 || position.y < -100 || position.x > 1300 || position.y > 900) {
        game.despawnEntity(this);
        std::cout << "caiu pra fora" << std::endl;
    }

    // checagem de colisões do player, base e inimigos com o projetil
    Player* player = game.getPlayer();
    if (player->hitbox.collided(this->hitbox)) {
        std::cout << "REEEEEEEEEEEEEEE" << std::endl;
        player->loseHealth(1);
        game.despawnEntity(this);
    }

    Base* base = game.getBase();
    if (base->hitbox.collided(this->hitbox)) {
        std::cout << "IEHHHHHHHHHHHHHHH" << std::endl;
        base->loseHealth(5);
        game.despawnEntity(this);
    }

    std::vector<Enemy*> enemies = game.getEnemies();
    for (Enemy* enemy : enemies) {
        if (enemy->hitbox.collided(this->hitbox)) {
            std::cout << "AAAAAAAAAAAAAAAA" << std::endl;
            player->increaseKills(1);
            game.despawnEntity(enemy);
            game.despawnEntity(this);
            if (std::rand() % 4 != 0) {
                Ammo* ammo = new Ammo(position);
                game.spawnEntity(ammo);
            }
        }
    }
}

void Projectile::render(sf::RenderWindow& window, Game& game) {
    // renderiza o projetil
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

