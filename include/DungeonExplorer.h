#ifndef DUNGEONEXPLORER_H
#define DUNGEONEXPLORER_H

#include "Character.h"
#include "Dungeon.h"
#include "Combat.h"
#include "Inventory.h"
#include "GameState.h"
#include "HowToPlay.h"
#include "SaveLoad.h"

class DungeonExplorer {
private:
    Character* player;
    Dungeon* dungeon;
    Combat* combat;
    Inventory* inventory;
    GameState* gameState;
    HowToPlay* howToPlay;
    SaveLoad* saveLoad;
public:
    DungeonExplorer();
    ~DungeonExplorer();
    void start();
    void mainLoop();
    void characterSelection();
    void showHowToPlay();
    void saveGame();
    void loadGame();
    void handleLoss();
};

#endif