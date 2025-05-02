#include "Rogue.h"
#include <iostream>
using namespace std;

Rogue::Rogue(const string& name) : Character(name, 90, 50) {}

Rogue::~Rogue() {}

void Rogue::attack() {
    cout << name << " swiftly attacks with daggers!" << endl;

}

void Rogue::specialAbility() {
    cout << name << " uses special ability: Heal Self!" << endl;
    healSelf(20);
}

void Rogue::healSelf(int amount) {
    cout << name << " heals for " << amount << " health points." << endl;
    setHealth(getHealth() + amount);
}