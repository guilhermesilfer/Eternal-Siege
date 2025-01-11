#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy(int initialX, int initialY);
    void moveTowards(int targetX, int targetY, float deltaTime);
    int getX() const;
    int getY() const;

private:
    float x;
    float y;
    float speed = 100.f;
};

#endif

