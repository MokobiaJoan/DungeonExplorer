#ifndef POTION_H
#define POTION_H

#include "Item.h"

class Potion : public Item {
private:
    int healthRestore;
public:
    Potion(const std::string& name, const std::string& effect, int healthRestore);
    virtual ~Potion();
    void drink();
    virtual void use(Character* player) override;
};

#endif