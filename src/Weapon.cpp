#include "Weapon.h"
#include <iostream>
using namespace std;

Weapon::Weapon(const std::string& name, const std::string& effect, int damage)
    : Item(name, effect), damage(damage) {}

Weapon::~Weapon() {}

void Weapon::swing() {
    cout << "Swinging " << name << " for " << damage << " damage." << endl;
}

void Weapon::use(Character* player) {
    cout << player->getName() << " uses " << name << ". " << effect << endl;
}