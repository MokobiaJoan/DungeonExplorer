#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory() {}

Inventory::~Inventory() {
    for (auto item : items) {
        delete item;
    }
}

void Inventory::addItem(Item* item) {
    items.push_back(item);
    cout << item->getName() << " added to inventory." << endl;
}

void Inventory::useItem(const std::string& itemName, Character* player) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {
            (*it)->use(player);
            delete *it;
            items.erase(it);
            return;
        }
    }
    cout << "Item " << itemName << " not found in inventory." << endl;
}