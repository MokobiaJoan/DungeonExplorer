#include "Room.h"
#include "Enemy.h"
#include "NPC.h"
#include "Item.h"
#include "Potion.h"
# include "Inventory.h"
#include <iostream>
using namespace std;

Room::Room(const string& desc) : description(desc), enemy(nullptr), npc(nullptr) {}

Room::~Room() {
    if(enemy) delete enemy;
    if(npc) delete npc;
}

void Room::enter(Inventory* inventory) {
    cout << description << endl;

    Potion* potion = new Potion("Health Potion", "Restores health", 30);
    cout << "You found a health potion! It's added to your inventory." << endl;
    inventory->addItem(potion);


    cout << "Oh no! You stepped on a trap and take 10 damage." << endl;
}

Enemy* Room::getEnemy() const {
    return enemy;
}

void Room::setEnemy(Enemy* e) {
    enemy = e;
}

NPC* Room::getNPC() const {
    return npc;
}

void Room::setNPC(NPC* n) {
    npc = n;
}