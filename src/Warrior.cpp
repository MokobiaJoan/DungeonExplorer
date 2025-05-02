#include "Warrior.h"

Warrior::Warrior(const std::string &name)
    : Character(name, 120, 30)
{}

Warrior::~Warrior() {}

void Warrior::attack()        {}
void Warrior::specialAbility() {}