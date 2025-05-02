
#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>

class Room;

class Dungeon {
private:

    std::vector<Room*> rooms;

public:
    Dungeon();
    ~Dungeon();

    void addRoom(Room* room);

    std::vector<Room*>& getRooms();
    void explore();
};

#endif