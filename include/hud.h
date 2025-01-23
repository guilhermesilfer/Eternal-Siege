#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "game.h"

class Hud : public Entity {
public:
    Hud();
    void processInput(sf::Event& event, Game& game);
    void update(float delta, Game& game);
    void render(sf::RenderWindow& window, Game& game);

private:
    int ammo;
};

#endif


