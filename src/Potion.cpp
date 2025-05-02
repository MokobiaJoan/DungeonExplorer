#include "Potion.h"
#include <iostream>
using namespace std;

Potion::Potion(const std::string& name, const std::string& effect, int healthRestore)
    : Item(name, effect), healthRestore(healthRestore) {}

Potion::~Potion() {}

void Potion::drink() {
    cout << "Drinking " << name << " to restore " << healthRestore << " health." << endl;
}

void Potion::use(Character* player) {
    drink();
    player->setHealth(player->getHealth() + healthRestore);
    cout << player->getName() << "'s health is now " << player->getHealth() << endl;
}