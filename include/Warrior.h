#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
public:
    Warrior(const std::string &name);
    ~Warrior() override;
    void attack() override;
    void specialAbility() override;
};

#endif