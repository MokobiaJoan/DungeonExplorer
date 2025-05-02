#include "Character.h"

Character::Character(const std::string &name, int health, int mana)
    : name(name), health(health), mana(mana)
{}

Character::~Character() {}

std::string Character::getName() const { return name; }
int Character::getHealth() const   { return health; }
int Character::getMana() const     { return mana; }
void Character::setHealth(int h)   { health = h; }
void Character::setMana(int m)     { mana = m; }
void Character::displayStatus() const {}