#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Armor : public Item {
private:
    int defense;
public:
    Armor(const std::string& name, const std::string& effect, int defense);
    virtual ~Armor();
    void equip();
    virtual void use(Character* player) override;
};

#endif