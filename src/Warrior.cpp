#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(const string& name) : Character(name, 48, 10) {
    shield = new Shield(20); // Example block power
}

Warrior::~Warrior() {
    delete shield;
}

void Warrior::attack() {
    cout << name << " swings his sword!" << endl;

}

void Warrior::specialAbility() {
    cout << name << " uses his special ability: Shield Block!" << endl;
    useShield();
}

void Warrior::useShield() {
    cout << name << " blocks with his shield, reducing incoming damage by " << shield->getBlockPower() << "!" << endl;
}