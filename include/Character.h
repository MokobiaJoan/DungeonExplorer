#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int mana;
public:
    Character(const std::string &name, int health, int mana);
    virtual ~Character();
    std::string getName() const;
    int getHealth() const;
    int getMana() const;
    void setHealth(int h);
    void setMana(int m);
    virtual void attack() = 0;
    virtual void specialAbility() = 0;
    virtual void displayStatus() const;
};

#endif