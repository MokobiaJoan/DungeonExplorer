#ifndef COMBAT_H
#define COMBAT_H

#include "Character.h"

class Enemy;

class Combat {
private:
    Character* player;
    Enemy* enemy;
    int turnCounter;
public:
    Combat();
    ~Combat();
    void setPlayer(Character* player);
    void setEnemy(Enemy* enemy);
    void engage();
    void playerTurn();
    void enemyTurn();
};

#endif