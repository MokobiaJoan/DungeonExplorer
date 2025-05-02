
#include "Mage.h"

Mage::Mage(const std::string &name)
    : Character(name, 80, 100)
{}

Mage::~Mage() {}

void Mage::attack()        {}
void Mage::specialAbility() {}