#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
private:
    int playerHealth;
    int playerMana;
    int currentRoomIndex;
public:
    GameState();
    int getPlayerHealth() const;
    int getPlayerMana() const;
    int getCurrentRoomIndex() const;
    void setPlayerHealth(int health);
    void setPlayerMana(int mana);
    void setCurrentRoomIndex(int index);
};

#endif