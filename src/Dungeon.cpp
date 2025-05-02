
#include "Dungeon.h"
#include "Room.h" 

Dungeon::Dungeon() {

}

Dungeon::~Dungeon() {

    for (Room* r : rooms) {
        delete r;
    }
    rooms.clear();
}

void Dungeon::addRoom(Room* room) {
    rooms.push_back(room);
}

std::vector<Room*>& Dungeon::getRooms() {
    return rooms;
}

void Dungeon::explore() {

}