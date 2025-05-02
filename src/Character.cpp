#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(const string& name, int health, int mana)
    : name(name), health(health), mana(mana) {}

Character::~Character() {}

string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getMana() const {
    return mana;
}

void Character::setHealth(int h) {
    health = h;
}

void Character::setMana(int m) {
    mana = m;
}

void Character::displayStatus() const {
    cout << "Character: " << name << ", Health: " << health << ", Mana: " << mana << endl;
}