#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item {
private:
    int damage;
public:
    Weapon(const std::string& name, const std::string& effect, int damage);
    virtual ~Weapon();
    void swing();
    virtual void use(Character* player) override;
};

#endif