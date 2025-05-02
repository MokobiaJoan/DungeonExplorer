#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
protected:
    string name;
    int health;
    int mana;
public:
    Character(const string& name, int health, int mana);
    virtual ~Character();
    string getName() const;
    int getHealth() const;
    int getMana() const;
    void setHealth(int h);
    void setMana(int m);
    virtual void attack() = 0;
    virtual void specialAbility() = 0;
    virtual void displayStatus() const;
};

#endif