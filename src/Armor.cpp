#include "Armor.h"
#include <iostream>
using namespace std;

Armor::Armor(const std::string& name, const std::string& effect, int defense)
    : Item(name, effect), defense(defense) {}

Armor::~Armor() {}

void Armor::equip() {
    cout << "Equipping " << name << " with defense " << defense << "." << endl;
}

void Armor::use(Character* player) {
    cout << player->getName() << " equips " << name << ". " << effect << endl;
}