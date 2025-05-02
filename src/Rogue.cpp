#include "Rogue.h"

Rogue::Rogue(const std::string &name)
    : Character(name, 90, 50)
{}

Rogue::~Rogue() {}

void Rogue::attack()        {}
void Rogue::specialAbility() {}