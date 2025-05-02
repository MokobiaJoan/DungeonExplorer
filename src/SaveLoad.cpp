#include "SaveLoad.h"
#include <fstream>
#include <iostream>
using namespace std;

void SaveLoad::saveGame(const GameState& gameState) {
    ofstream file("savegame.txt");
    if(file.is_open()) {
        file << gameState.getPlayerHealth() << " " 
             << gameState.getPlayerMana() << " " 
             << gameState.getCurrentRoomIndex();
        file.close();
        cout << "Game saved successfully." << endl;
    } else {
        cout << "Error saving game." << endl;
    }
}

GameState SaveLoad::loadGame() {
    GameState gs;
    ifstream file("savegame.txt");
    if(file.is_open()) {
        int health, mana, roomIndex;
        file >> health >> mana >> roomIndex;
        gs.setPlayerHealth(health);
        gs.setPlayerMana(mana);
        gs.setCurrentRoomIndex(roomIndex);
        file.close();
        cout << "Game loaded successfully." << endl;
    } else {
        cout << "Error loading game. Starting new game." << endl;
    }
    return gs;
}