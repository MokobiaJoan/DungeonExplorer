#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(const string& name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {}

Enemy::~Enemy() {}

string Enemy::getName() const {
    return name;
}

int Enemy::getHealth() const {
    return health;
}

void Enemy::setHealth(int h) {
    health = h;
}

void Enemy::attack() {
    cout << name << " attacks with power " << attackPower << "!" << endl;
}

void Enemy::specialAbility() {
    cout << name << " uses a special ability!" << endl;
}

void Enemy::decideAction(Character* player) {

    attack();
    int newHealth = player->getHealth() - attackPower;
    player->setHealth(newHealth);
    cout << player->getName() << "'s health is now " << player->getHealth() << endl;
}