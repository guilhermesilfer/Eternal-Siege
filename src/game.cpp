#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"

Game::Game() : window(sf::VideoMode(1280, 800), "Eternal Siege"),
               spawnTimer(0),
               spawnInterval(4.0f)
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
        // processa o input das entidades
        for (Entity* entity : entities) {
            std::cout << entities.size() << std::endl;
            std::cout << entities.size() << std::endl;
            std::cout << entities.size() << std::endl;
            std::cout << entity << std::endl;
//            std::cout << entity << std::endl;
//            std::cout << entity << std::endl;
//            std::cout << entity << std::endl;
            entity->processInput(event, *this);
            std::cout << "balls" << std::endl;
            std::cout << "balls" << std::endl;
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
    // spawn dos inimigos
    //spawnTimer += delta;
    //if (spawnTimer >= spawnInterval) {
    //    Enemy* enemy = new Enemy();
    //    entities.push_back(enemy);
    //    spawnTimer = 0;
    //}

    // update de todas as entidades
    for (Entity* entity : entities) {
        entity->update(delta, *this);
    }
}

void Game::render() {
    window.clear(sf::Color::White);

    for (Entity* entity : entities) {
        entity->render(window, *this);
    }

    window.display();
}

void Game::spawnEntity(Entity* entity) {
    entities.push_back(entity);
}

Player* Game::getPlayer() {
    return player;
}

