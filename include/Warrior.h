#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include "Shield.h"

class Warrior : public Character {
private:
    Shield* shield;
public:
    Warrior(const string& name);
    virtual ~Warrior();
    virtual void attack() override;
    virtual void specialAbility() override; // Uses shield
    void useShield();
};

#endif