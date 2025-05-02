#ifndef ROOM_H
#define ROOM_H

#include <string>

class Enemy;
class NPC;
class Inventory;

class Room {
private:
    std::string description;
    Enemy* enemy;
    NPC* npc;
public:
    Room(const std::string& desc);
    ~Room();
    void enter(Inventory* inventory);
    Enemy* getEnemy() const;
    void setEnemy(Enemy* enemy);
    NPC* getNPC() const;
    void setNPC(NPC* npc);
};

#endif