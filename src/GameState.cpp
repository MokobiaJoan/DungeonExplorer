#include "GameState.h"

GameState::GameState() : playerHealth(0), playerMana(0), currentRoomIndex(0) {}

int GameState::getPlayerHealth() const {
    return playerHealth;
}

int GameState::getPlayerMana() const {
    return playerMana;
}

int GameState::getCurrentRoomIndex() const {
    return currentRoomIndex;
}

void GameState::setPlayerHealth(int health) {
    playerHealth = health;
}

void GameState::setPlayerMana(int mana) {
    playerMana = mana;
}

void GameState::setCurrentRoomIndex(int index) {
    currentRoomIndex = index;
}