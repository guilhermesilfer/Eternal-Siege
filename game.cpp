#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game()
    : window(sf::VideoMode(800, 600), "SFML Game"), 
      spawnTimer(0), spawnInterval(2.0f) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    window.setFramerateLimit(60);
}

void Game::run() {
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        processInput();
        update(deltaTime);
        render();
    }
}

void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f target(event.mouseButton.x, event.mouseButton.y);
                player.setTarget(target);
            }
        }
    }
}

void Game::update(float deltaTime) {
    spawnTimer += deltaTime;
    if (spawnTimer >= spawnInterval) {
        spawnEnemy();
        spawnTimer = 0;
    }

    player.moveTowardsMouse(deltaTime);

    for (auto& enemy : enemies) {
        enemy.moveTowards(player.getX(), player.getY(), deltaTime);
    }
}

void Game::render() {
    window.clear(sf::Color::Black);

    sf::CircleShape playerShape(10.f);
    playerShape.setFillColor(sf::Color::Green);
    playerShape.setPosition(player.getX(), player.getY());
    window.draw(playerShape);

    for (const auto& enemy : enemies) {
        sf::CircleShape enemyShape(10.f);
        enemyShape.setFillColor(sf::Color::Red);
        enemyShape.setPosition(enemy.getX(), enemy.getY());
        window.draw(enemyShape);
    }

    window.display();
}

void Game::spawnEnemy() {
    int x = std::rand() % 800;
    int y = std::rand() % 600;
    enemies.emplace_back(x, y);
}

