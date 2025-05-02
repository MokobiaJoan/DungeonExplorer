#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

class Enemy;

class Mage : public Character {
public:
    Mage(const string& name);
    virtual ~Mage();
    virtual void attack() override;
    virtual void specialAbility() override;
    void strikeTwice(Enemy* enemy);
};

#endif