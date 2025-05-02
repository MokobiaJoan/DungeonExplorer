#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Character.h"

class Character;

class Item {
protected:
    std::string name;
    std::string effect;
public:
    Item(const std::string& name, const std::string& effect);
    virtual ~Item();
    std::string getName() const;
    std::string getEffect() const;
    virtual void use(Character* player) = 0;
};

#endif