
#ifndef ROGUE_H
#define ROGUE_H

#include "Character.h"

class Rogue : public Character {
public:
    Rogue(const std::string &name);
    ~Rogue() override;
    void attack() override;
    void specialAbility() override;
};

#endif