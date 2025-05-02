#ifndef SAVELOAD_H
#define SAVELOAD_H

#include "GameState.h"

class SaveLoad {
public:
    void saveGame(const GameState& gameState);
    GameState loadGame();
};

#endif