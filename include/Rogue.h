#ifndef ROGUE_H
#define ROGUE_H

#include "Character.h"

class Rogue : public Character {
public:
    Rogue(const string& name);
    virtual ~Rogue();
    virtual void attack() override;
    virtual void specialAbility() override;
    void healSelf(int amount);
};

#endif