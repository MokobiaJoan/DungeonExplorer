#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include "Item.h"

class Inventory {
private:
    std::vector<Item*> items;
public:
    Inventory();
    ~Inventory();
    void addItem(Item* item);
    void useItem(const std::string& itemName, Character* player);
};

#endif