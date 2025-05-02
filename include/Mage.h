#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

class Mage : public Character {
public:
    Mage(const std::string &name);
    ~Mage() override;
    void attack() override;
    void specialAbility() override;
};

#endif