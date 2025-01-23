#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "hud.h"

Game::Game() :
    window(sf::VideoMode(1280, 800), "Eternal Siege"),
    entities(),
    player(new Player()),
    spawnTimer(0),
    spawnInterval(4.0f)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    window.setFramerateLimit(60);
    spawnEntity(player);

    Hud* hud = new Hud();
    spawnEntity(hud);
}

void Game::run() {
    while (window.isOpen()) {
        float delta = clock.restart().asSeconds();
        processInput();
        update(delta);
        render();
    }
}

void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }

        // processa o input das entidades
        for (Entity* entity : std::vector<Entity*>(entities)) {
            entity->processInput(event, *this);
        }
    }
}

void Game::update(float delta) {
    // spawn dos inimigos
    spawnTimer += delta;
    if (spawnTimer >= spawnInterval) {
        Enemy* enemy = new Enemy();
        spawnEntity(enemy);
        spawnTimer = 0;
    }

    // update de todas as entidades
    for (Entity* entity : std::vector<Entity*>(entities)) {
        entity->update(delta, *this);
    }
}

void Game::render() {
    window.clear(sf::Color::White);

    for (Entity* entity : std::vector<Entity*>(entities)) {
        entity->render(window, *this);
    }

    window.display();
}

void Game::spawnEntity(Entity* entity) {
    entities.push_back(entity);
}

//void Game::despawnEntity(Entity* entity) {
//   /* ... */
//}

Player* Game::getPlayer() {
    return player;
}

std::vector<Enemy*> Game::getEnemies() {
    std::vector<Enemy*> enemies;
    for (Entity* entity : std::vector<Entity*>(entities)) {
        if (dynamic_cast<Enemy*>(entity) != nullptr) {
            enemies.push_back(static_cast<Enemy*>(entity));
        }
    }
    return enemies;
}
