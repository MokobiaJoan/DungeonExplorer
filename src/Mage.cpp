#include "Mage.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

Mage::Mage(const string& name) : Character(name, 80, 100) {}

Mage::~Mage() {}

void Mage::attack() {
    cout << name << " casts a fireball!" << endl;
}

void Mage::specialAbility() {
    cout << name << " uses special ability: Strike Twice!" << endl;
}

void Mage::strikeTwice(Enemy* enemy) {
    cout << name << " strikes twice at " << enemy->getName() << "!" << endl;
}