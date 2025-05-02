#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "Character.h"

class Enemy {
private:
    std::string name;
    int health;
    int attackPower;
public:
    Enemy(const std::string& name, int health, int attackPower);
    ~Enemy();
    std::string getName() const;
    int getHealth() const;
    void setHealth(int h);
    void attack();
    void specialAbility();
    void decideAction(Character* player);
};

#endif