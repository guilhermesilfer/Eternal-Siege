#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game.h"
#include "entity.h"
#include "player.h"

Game::Game() : window(sf::VideoMode(1280, 800), "Eternal Siege"),
               spawnTimer(0),
               spawnInterval(0.5f)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    window.setFramerateLimit(60);
    player = new Player();
    entities.push_back(player);
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
        for (Entity* entity : entities) {
            entity->processInput(event);
        }

        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }
    }
}

void Game::update(float delta) {
    spawnTimer += delta;
    if (spawnTimer >= spawnInterval) {
        //spawnEnemy();
        spawnTimer = 0;
    }

    for (Entity* entity : entities) {
        entity->update(delta, *this);
    }
}

void Game::render() {
    window.clear(sf::Color::White);

    for (Entity* entity : entities) {
        entity->render(window);
    }

//for (const auto& enemy : enemies) {
//    sf::CircleShape enemyShape(10.f);
//    enemyShape.setFillColor(sf::Color::Red);
//    enemyShape.setPosition(enemy.getX(), enemy.getY());
//    window.draw(enemyShape);
//}

    window.display();
}

Player* Game::getPlayer() {
    return player;
}

